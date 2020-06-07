
/*
 * Christos Gogos
 * University of Ioannina 
 * May - 2020
 * 
 */
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Vector;
import java.util.concurrent.ThreadLocalRandom;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Fractal extends JFrame {

	public static int WIDTH = 1_000;
	public static int HEIGHT = 1_000;
	public static final int V = 5; // # of initial vertices (5 for pentagon)
	public static int T = 10; // # THREADS
	public static final int POINTS_PER_THREAD = 100_000;

	private Vector<Point> regular_polygon_vertices = new Vector<Point>();
	private Vector<Point> points[] = new Vector[T];

	public static void main(String[] args) {
		if (args.length != 2) {
			System.out.println("No argument, assuming  threads T = 10 and HEIGHT = WIDTH = 1000 pixels");
			System.out.println("Example (4 threads, 2000x2000 pixels): java Fractal 4 2000");
			T = 10;
			HEIGHT = WIDTH = 1000;
		}
		else {
			T = Integer.parseInt(args[0]);
			HEIGHT = WIDTH = Integer.parseInt(args[1]);
		}
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					new Fractal("Fractal");
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});
	}

	@Override
	public void paint(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		Color color = new Color(255, 0, 0);
		for (Point p : regular_polygon_vertices) {
			g2d.setColor(color);
			g2d.fillOval((int) p.x, (int) p.y, 10, 10);
		}
		// draw points
		for (int i = 0; i < T; i++) {
			g2d.setColor(Color.getHSBColor((float) i / T, 1, 1)); // cycle through colors
			for (Point p : points[i]) {
				g2d.fillOval((int) p.x, (int) p.y, 2, 2);
			}
		}
	}

	private void generateRegularPolygon(double start_angle) {
		double x, y, radius = HEIGHT / 2 - 50;
		for (int i = 0; i < V; i++) {
			x = radius * Math.cos(start_angle + i * 2 * Math.PI / V);
			y = radius * Math.sin(start_angle + i * 2 * Math.PI / V);
			x += WIDTH / 2;
			y += HEIGHT / 2;
			System.out.printf("Vertex (%d): x=%.2f y=%.2f\n", i, x, y);
			regular_polygon_vertices.add(new Point(x, y));
		}
	}

	public Fractal(String title) throws InterruptedException {
		super(title);
		setSize(WIDTH, HEIGHT);
		setLayout(new BorderLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setVisible(true);
		generateRegularPolygon(Math.PI / 6); // PI/6 RADS = 30 DEGREES
		Thread myThreads[] = new Thread[T];
		for (int i = 0; i < T; i++) {
			points[i] = new Vector<Point>();
			final int thread_id = i;
			myThreads[i] = new Thread(() -> {
				Point a_point = new Point(ThreadLocalRandom.current().nextDouble() * WIDTH,
						ThreadLocalRandom.current().nextDouble() * HEIGHT);
				int v = 0;
				Graphics2D g2d = (Graphics2D) getGraphics();
				while (v < POINTS_PER_THREAD) {
					int chosen_vertex = ThreadLocalRandom.current().nextInt(V);
					a_point = generate_new_point(a_point, regular_polygon_vertices.get(chosen_vertex));
					points[thread_id].add(a_point);
					g2d.fillOval((int) a_point.x, (int) a_point.y, 1, 1);
					v++;
				}
			});
			myThreads[i].start();
		}
		for (int i = 0; i < T; i++)
			myThreads[i].join();
	}

	private Point generate_new_point(Point point1, Point point2) {
		return new Point((point1.x + point2.x) / 2.0, (point1.y + point2.y) / 2.0);
	}

	class Point {
		public double x;
		public double y;
		public Point(double _x, double _y) {
			x = _x;
			y = _y;
		}
	}
}

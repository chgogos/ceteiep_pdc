/*
 * Christos Gogos
 * University of Ioannina 
 * May - 2020
 */

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Pentagon extends JFrame {

	public final static int WIDTH = 1000;
	public final static int HEIGHT = 1000;
	public static final int V = 5; // # of initial vertices (5 for pentagon)

	private Vector<Point> polygon_vertices = new Vector<Point>();

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				new Pentagon("Pentagon");
			}
		});
	}

	public Pentagon(String title) {
		super(title);
		setSize(WIDTH, HEIGHT);
		setLayout(new BorderLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setVisible(true);
		generateRegularPolygon(Math.PI / 6); // PI/6 RADS = 30 DEGREES (first vertex at 30 DEGREES)
	}

	@Override
	public void paint(Graphics g) {
		Graphics2D g2d = (Graphics2D) g;
		g2d.setColor(Color.RED);
		for (Point p : polygon_vertices) {
			g2d.fillOval((int) p.x, (int) p.y, 10, 10);
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
			polygon_vertices.add(new Point(x, y));
		}
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

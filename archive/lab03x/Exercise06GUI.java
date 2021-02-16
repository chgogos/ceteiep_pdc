import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.ThreadLocalRandom;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JProgressBar;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;

import org.apache.commons.lang3.tuple.Pair;

public class Exercise06GUI extends JFrame {
	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {

			@Override
			public void run() {
				new Exercise06GUI("PI");
			}
		});
	}

	BlockingQueue<Pair<Double, Double>> buffer;
	private JLabel la0 = new JLabel("Iterations");
	private JLabel la1 = new JLabel("Threads");
	private JLabel la2 = new JLabel("Pi");
	private JTextField tf0 = new JTextField("300000");
	private JTextField tf1 = new JTextField("8");
	private JButton bu0 = new JButton("Start");
	private JPanel pa0 = new JPanel() {
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			((Graphics2D) g).setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
			g.setColor(Color.RED);
			((Graphics2D) g).setStroke(new BasicStroke(2));
			g.drawOval(2, 2, this.getWidth() - 4, this.getHeight() - 4);
		}
	};
	private JProgressBar pb = new JProgressBar(1, 100);

	public Exercise06GUI(String title) {
		super(title);
		buffer = new ArrayBlockingQueue<>(5000);
		setLayout(new GridBagLayout());
		GridBagConstraints gc = new GridBagConstraints();
		gc.fill = GridBagConstraints.HORIZONTAL;

		gc.gridx = 0;
		gc.gridy = 0;
		add(la0, gc);

		gc.gridx = 1;
		gc.gridy = 0;
		add(tf0, gc);

		gc.gridx = 0;
		gc.gridy = 1;
		add(la1, gc);

		gc.gridx = 1;
		gc.gridy = 1;
		add(tf1, gc);

		gc.gridx = 0;
		gc.gridy = 2;
		add(bu0, gc);

		gc.gridx = 1;
		gc.gridy = 2;
		add(la2, gc);

		gc.gridx = 0;
		gc.gridy = 3;
		gc.gridwidth = 2;
		gc.ipadx = 400;
		gc.ipady = 400;
		add(pa0, gc);

		gc.ipadx = 400;
		gc.ipady = 0;
		gc.gridx = 0;
		gc.gridy = 4;
		add(pb, gc);

		bu0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				throwPoints();
			}
		});

		setSize(600, 600);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setLocationRelativeTo(null);
		setVisible(true);

	}

	@SuppressWarnings("unchecked")
	protected void throwPoints() {
		SwingWorker<Double, Void> worker = new SwingWorker<Double, Void>() {
			@Override
			protected Double doInBackground() throws Exception {
				int number_of_points = Integer.parseInt(tf0.getText());
				int number_of_threads = Integer.parseInt(tf1.getText());
				ExecutorService executor = Executors.newFixedThreadPool(number_of_threads);
				Future<Integer> futures[] = new Future[number_of_threads];
				int points_inside_circle[] = new int[number_of_threads];
				for (int i = 0; i < futures.length; i++) {
					futures[i] = executor.submit(new RandomPointThrower(buffer, number_of_points / number_of_threads));
					points_inside_circle[i] = 0;
				}
				executor.shutdown();

				Thread ct = new Thread(new Consumer(buffer, number_of_points));
				ct.start();

				for (int i = 0; i < futures.length; i++) {
					try {
						points_inside_circle[i] = futures[i].get();
					} catch (InterruptedException | ExecutionException e) {
						e.printStackTrace();
					}
				}

				int sum = 0;
				for (int i = 0; i < number_of_threads; i++)
					sum += points_inside_circle[i];

				return (double) sum / (double) number_of_points * 4;
			}

			protected void done() {
				try {
					la2.setText(String.valueOf(get()));
				} catch (InterruptedException e) {
					e.printStackTrace();
				} catch (ExecutionException e) {
					e.printStackTrace();
				}
			}
		};
		worker.execute();
	}

	class RandomPointThrower implements Callable<Integer> {
		BlockingQueue<Pair<Double, Double>> buffer;
		int number_of_points;
		Color color;

		public RandomPointThrower(BlockingQueue<Pair<Double, Double>> buffer, int number_of_points) {
			this.number_of_points = number_of_points;
			this.buffer = buffer;
			color = new Color(ThreadLocalRandom.current().nextInt(256), ThreadLocalRandom.current().nextInt(256),
					ThreadLocalRandom.current().nextInt(256));
		}

		@Override
		public Integer call() throws Exception {
			int c = 0;
			for (int i = 0; i < number_of_points; i++) {
				double x = ThreadLocalRandom.current().nextDouble();
				double y = ThreadLocalRandom.current().nextDouble();
				Graphics2D g2d = (Graphics2D) pa0.getGraphics();
				g2d.setColor(color);
				g2d.fillOval((int) (x * pa0.getWidth()), (int) (y * pa0.getWidth()), 2, 2);
				x = x * 2 - 1;
				y = y * 2 - 1;
				buffer.put(Pair.of(x, y));
				double d = Math.sqrt(x * x + y * y);
				if (d < 1)
					c++;

			}
			return c;
		}
	}

	class Consumer implements Runnable {
		BlockingQueue<Pair<Double, Double>> buffer;
		int points;

		public Consumer(BlockingQueue<Pair<Double, Double>> buffer, int points) {
			this.buffer = buffer;
			this.points = points;
			pb.setMaximum(points);
		}

		@Override
		public void run() {
			int c = 0;
			int c2 = 0;
			while (c < points) {
				try {
					Pair<Double, Double> p = buffer.take();
					double x = p.getLeft();
					double y = p.getRight();
					double d = Math.sqrt(x * x + y * y);
					if (d < 1)
						c2++;
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				c++;
				if (c % 10000 == 0) {
					pb.setValue(c);
					la2.setText(String.valueOf((double) c2 / (double) c * 4));
				}
			}
		}
	}
}

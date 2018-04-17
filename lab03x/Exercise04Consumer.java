import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;

public class Exercise04Consumer implements Runnable {
	BlockingQueue<Integer> buffer;
	int items;
	int sum;

	public Exercise04Consumer(BlockingQueue<Integer> buffer, int items) {
		this.buffer = buffer;
		this.items = items;
		sum = 0;
	}

	public void run() {
		int c = 0;
		while (c < items) {
			try {
				Thread.sleep(ThreadLocalRandom.current().nextInt(2000));
				int x = buffer.take();
				sum += x;
				c++;
				System.out.printf("CONSUMER<--consumed %d buffer: %s\n", x, buffer);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Total sum " + sum);
	}
}

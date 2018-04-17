import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ThreadLocalRandom;

public class Exercise04Producer implements Runnable {
  BlockingQueue<Integer> buffer;
  int items;

  public Exercise04Producer(BlockingQueue<Integer> buffer, int items) {
    this.buffer = buffer;
    this.items = items;
  }

  public void run() {
    for (int i = 0; i < items; i++) {
      int r = ThreadLocalRandom.current().nextInt(1, 101);
      try {
        Thread.sleep(ThreadLocalRandom.current().nextInt(500));
        buffer.put(r);
        System.out.printf("PRODUCER-->produced %d buffer: %s\n", r, buffer);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}

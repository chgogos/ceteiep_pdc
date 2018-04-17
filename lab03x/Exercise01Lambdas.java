import java.util.concurrent.ThreadLocalRandom;

public class Exercise01Lambdas {
  public static void main(String[] args) throws InterruptedException {
    Thread myThreads[] = new Thread[10];
    for (int i = 0; i < 10; i++) {
      myThreads[i] = new Thread(() -> {
        int r = ThreadLocalRandom.current().nextInt(1, 101);
        System.out.printf("Thread %s produced value %d\n",
                          Thread.currentThread().getName(), r);
      });
      myThreads[i].start();
    }
    for (int i = 0; i < 10; i++)
      myThreads[i].join();

    System.out.println("Main thread finished");
  }
}

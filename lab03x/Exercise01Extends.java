import java.util.concurrent.ThreadLocalRandom;

class MyThread extends Thread {
  @Override
  public void run() {
    int r = ThreadLocalRandom.current().nextInt(1, 101);
    System.out.printf("Thread %s produced value %d\n",
                      Thread.currentThread().getName(), r);
  }
}

public class Exercise01Extends {
  public static void main(String[] args) throws InterruptedException {
    MyThread myThreads[] = new MyThread[10];
    for (int i = 0; i < 10; i++) {
      myThreads[i] = new MyThread();
      myThreads[i].start();
    }
    for (int i = 0; i < 10; i++)
      myThreads[i].join();

    System.out.println("Main thread finished");
  }
}

public class MsLunchExample {
  static MsLunch c = new MsLunch();
  private static class IncrementCounter1 implements Runnable {
    public void run() {
      for (int i = 0; i < 100; i++)
        c.inc1();
    }
  }

  private static class IncrementCounter2 implements Runnable {
    public void run() {
      for (int i = 0; i < 100; i++)
        c.inc2();
    }
  }

  public static void main(String[] args) throws InterruptedException {
    Thread threads1[] = new Thread[100];
    for (int i = 0; i < 100; i++)
      threads1[i] = new Thread(new IncrementCounter1());

    Thread threads2[] = new Thread[100];
    for (int i = 0; i < 100; i++)
      threads2[i] = new Thread(new IncrementCounter2());

    for (int i = 0; i < 100; i++) {
      threads1[i].start();
      threads2[i].start();
    }

    for (int i = 0; i < 100; i++) {
      threads1[i].join();
      threads2[i].join();
    }

    c.print();
  }
}
class SynchronizedCounter2Example {
  static SynchronizedCounter2 c = new SynchronizedCounter2();
  private static class IncrementCounter implements Runnable {
    public void run() {
      for (int i = 0; i < 100; i++) {
        if (i % 2 == 0)
          c.increment();
        else
          c.decrement();
      }
    }
  }

  public static void main(String[] args) throws InterruptedException {
    Thread[] threads = new Thread[100];
    for (int i = 0; i < 100; i++)
      threads[i] = new Thread(new IncrementCounter());

    System.out.println(c.value());

    for (int i = 0; i < 100; i++)
      threads[i].start();

    for (int i = 0; i < 100; i++)
      threads[i].join();

    System.out.println(c.value());
  }
}

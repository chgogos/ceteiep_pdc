class Waiter implements Runnable {
  private volatile boolean shouldFinish;
  void finish() { shouldFinish = true; }
  public void run() {
    long iteration = 0;
    while (!shouldFinish) {
      iteration++;
    }
    System.out.println("Finished after: " + iteration);
  }
}
class DataRaceVolatileFlag {
  public static void main(String[] args) throws InterruptedException {
    Waiter waiter = new Waiter();
    Thread waiterThread = new Thread(waiter);
    waiterThread.start();
    Thread.sleep(100);
    waiter.finish();
    waiterThread.join();
  }
}
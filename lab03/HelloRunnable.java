public class HelloRunnable implements Runnable {

  public void run() { System.out.println("Hello from a thread!"); }

  public static void main(String args[]) {
    Runnable aRunnable = new HelloRunnable();
    Thread aThread = new Thread(aRunnable);
    aThread.start();

    // or in one line
    // (new Thread(new HelloRunnable())).start();
  }
}

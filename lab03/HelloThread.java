public class HelloThread extends Thread {

  public void run() { System.out.println("Hello from a thread!"); }

  public static void main(String args[]) {
    Thread aThread = new HelloThread();
    aThread.start();

    // or in one line
    // (new HelloThread()).start();
  }
}

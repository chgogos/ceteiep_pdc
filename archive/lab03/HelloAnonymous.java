public class HelloAnonymous {

  public static void main(String args[]) {
    Thread aThread = new Thread(new Runnable() {
      @Override
      public void run() {
        System.out.println("Hello from a thread!");
      }
    });
    aThread.start();
  }
}

public class HelloLambdas {

  public static void main(String args[]) {
    Thread aThread = new Thread(()->{
        System.out.println("Hello from a thread!");
      });
    aThread.start();
  }
}

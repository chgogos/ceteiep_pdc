public class RGBExample {
  static SynchronizedRGB pixel1 =
      new SynchronizedRGB(0, 191, 255, "DeepSkyBlue");
  static ImmutableRGB pixel2 = new ImmutableRGB(0, 191, 255, "DeepSkyBlue");

  public static void main(String[] args) throws InterruptedException {
    Thread[] threads = new Thread[2];
    System.out.println("Pixel 1: " + pixel1.toString());
    System.out.println("Pixel 2: " + pixel2.toString());
    for (int i = 0; i < threads.length; i++) {
      threads[i] = new Thread(new TouchPixelThread());
      threads[i].start();
    }
    for (int i = 0; i < threads.length; i++)
      threads[i].join();
    System.out.println("Pixel 1: " + pixel1.toString());
    System.out.println("Pixel 2: " + pixel2.toString());
  }

  public static class TouchPixelThread implements Runnable {
    public void run() {
      for (int i = 0; i < 10; i++) {
        pixel1.invert();
        pixel2 = pixel2.invert();
      }
    }
  }
}

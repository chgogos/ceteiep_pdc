import java.util.Random;

public class Exercise08Synchronized {
  static Object lock = new Object();
  static int[] a;
  static int SUM;
  static final int N = 1_000_000;
  static final int T = 4;

  public static void main(String[] args) throws InterruptedException {
    long seed = 123456789L;
    Random random = new Random(seed);
    a = new int[N];
    int check_sum = 0;
    for (int i = 0; i < N; i++) {
      a[i] = random.nextInt(101);
      check_sum += a[i];
    }

    Thread threads[] = new Thread[T];
    for (int i = 0; i < T; i++) {
      threads[i] = new MyThread(i);
      threads[i].start();
    }

    for (int i = 0; i < T; i++) {
      threads[i].join();
    }
    if (check_sum == SUM)
      System.out.println("Correct!");
    else
      System.out.println("Incorrect!");
  }

  static class MyThread extends Thread {
    private int tid;
    public MyThread(int tid) { this.tid = tid; }

    @Override
    public void run() {
      int mysum = 0;
      for (int i = tid * N / T; i < (tid + 1) * N / T; i++) {
        mysum += a[i];
      }
      synchronized (lock) { SUM += mysum; }
    }
  }
}
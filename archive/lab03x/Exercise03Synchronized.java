import java.util.Random;

public class Exercise03Synchronized {
  static Object lock = new Object();
  static final int T = 4;
  static final int N = 1000;
  static int a[];
  static int b[];
  static int SUM;

  public static void main(String[] args) throws InterruptedException {
    long seed = 123456789L;
    Random rnd = new Random(seed);
    a = new int[N];
    b = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = rnd.nextInt(10) + 1;
      b[i] = rnd.nextInt(10) + 1;
    }
    Thread threads[] = new Thread[T];
    for (int tid = 0; tid < T; tid++) {
      threads[tid] = new Work(tid);
      threads[tid].start();
    }
    for (int tid = 0; tid < T; tid++) {
      threads[tid].join();
    }
    System.out.println("dot product " + SUM);
  }

  static class Work extends Thread {
    int tid;

    public Work(int id) { tid = id; }

    public void run() {
      int q = 0;
      for (int i = tid * N / T; i < (tid + 1) * N / T; i++)
        q += a[i] * b[i];
      synchronized (lock) { SUM += q; }
    }
  }
}

import java.util.Random;

public class Exercise07Lambda {

  static final int N = 1_000_000;
  static int a[];
  static int b[];
  static int c[];
  static final int NUM_THREADS = 4;

  public static void main(String[] args) throws InterruptedException {
    assert N % NUM_THREADS == 0
        : "The size of the vectors (N) should should be a multiply of NUM_THREADS";
    long seed = 123456789L;
    a = new int[N];
    b = new int[N];
    c = new int[N];
    int check_c[] = new int[N];
    Random random = new Random(seed);
    for (int i = 0; i < N; i++) {
      a[i] = random.nextInt(101);
      b[i] = random.nextInt(101);
      check_c[i] = a[i] + b[i];
    }

    Thread threads[] = new Thread[NUM_THREADS];
    for (int tid = 0; tid < NUM_THREADS; tid++) {
      final int ttid =
          tid; // local vars must be final inorder to be used in the lambda
      threads[tid] = new Thread(() -> {
        int stride = N / NUM_THREADS;
        for (int i = ttid * stride; i < (ttid + 1) * stride; i++)
          c[i] = a[i] + b[i];
      });
      threads[tid].start();
    }

    for (int tid = 0; tid < NUM_THREADS; tid++) {
      threads[tid].join();
    }

    boolean ok = true;
    for (int i = 0; i < N; i++) {
      if (c[i] != check_c[i]) {
        ok = false;
        break;
      }
    }
    if (ok)
      System.out.println("Correct!");
    else
      System.out.println("Incorrect!");
  }
}

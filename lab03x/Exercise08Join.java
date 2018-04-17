import java.util.Random;

public class Exercise08Join {
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

    MyThread threads[] = new MyThread[T];
    for (int i = 0; i < T; i++) {
      threads[i] = new MyThread(i);
      threads[i].start();
    }
    int sum = 0;
    for (int i = 0; i < T; i++) {
      threads[i].join();
      sum += threads[i].getMySum();
    }
    if (check_sum == sum)
      System.out.println("Correct!");
    else
      System.out.println("Incorrect!");
  }

  static class MyThread extends Thread {
    private int tid;
    private int mySum;

    public MyThread(int tid) {
      this.tid = tid;
      this.mySum = 0;
    }

    public int getMySum() { return mySum; }

    @Override
    public void run() {
      for (int i = tid * N / T; i < (tid + 1) * N / T; i++) {
        mySum += a[i];
      }
    }
  }
}
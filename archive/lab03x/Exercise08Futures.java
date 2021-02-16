import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Exercise08Futures {
  static int[] a;
  static final int N = 1_000_000;
  static final int T = 4;

  public static void main(String[] args)
      throws InterruptedException, ExecutionException {
    long seed = 123456789L;
    Random random = new Random(seed);
    a = new int[N];
    int check_sum = 0;
    for (int i = 0; i < N; i++) {
      a[i] = random.nextInt(101);
      check_sum += a[i];
    }

    ExecutorService executor = Executors.newCachedThreadPool();
    List<Future<Integer>> futures = new ArrayList<>(T);
    for (int i = 0; i < T; i++) {
      futures.add(executor.submit(new MyCallable(i)));
    }
    executor.shutdown();
    
    int sum = 0;
    for (int i = 0; i < T; i++) {
      Integer x = futures.get(i).get();
      sum += x;
    }

    if (check_sum == sum)
      System.out.println("Correct!");
    else
      System.out.println("Incorrect!");
  }

  static class MyCallable implements Callable<Integer> {
    private int tid;
    public MyCallable(int tid) { this.tid = tid; }

    @Override
    public Integer call() {
      int mySum = 0;
      for (int i = tid * N / T; i < (tid + 1) * N / T; i++) {
        mySum += a[i];
      }
      return mySum;
    }
  }
}

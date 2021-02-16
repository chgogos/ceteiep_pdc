import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class Exercise03Futures {
  static final int T = 4;
  static final int N = 1000;
  static int a[];
  static int b[];

  public static void main(String[] args)
      throws InterruptedException, ExecutionException {
    int sum = 0;
    long seed = 123456789L;
    Random rnd = new Random(seed);
    a = new int[N];
    b = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = rnd.nextInt(10) + 1;
      b[i] = rnd.nextInt(10) + 1;
	}
	
    ExecutorService executor = Executors.newCachedThreadPool();
    List<Future<Integer>> futures = new ArrayList<>(T);

    for (int i = 0; i < T; i++) {
      Future<Integer> afuture = executor.submit(new Work(i));
      futures.add(afuture);
    }

    executor.shutdown();

    for (int i = 0; i < T; i++) {
      Integer x = futures.get(i).get();
      sum += x;
    }
    System.out.println("dot product " + sum);
  }

  static class Work implements Callable<Integer> {
    int tid;

    public Work(int id) { tid = id; }

    @Override
    public Integer call() throws Exception {
      int q = 0;
      for (int i = tid * N / T; i < (tid + 1) * N / T; i++)
        q += a[i] * b[i];
      return q;
    }
  }
}

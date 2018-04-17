import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Exercise02Futures {
  static Lock lock = new ReentrantLock();
  static long SUM = 0;
  static long X;
  static int NUMBER_OF_THREADS;

  @SuppressWarnings("unchecked")
  public static void main(String[] args) {
    if (args.length == 0) {
      X = 10_000_000;
      NUMBER_OF_THREADS = 4;
    } else {
      X = Long.parseLong(args[0]);
      NUMBER_OF_THREADS = Integer.parseInt(args[1]);
    }

    ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);
    Future<Long> futures[] = new Future[NUMBER_OF_THREADS];
    for (int tid = 0; tid < futures.length; tid++)
      futures[tid] = executor.submit(new Totalizator(tid));

    executor.shutdown();

    for (int tid = 0; tid < futures.length; tid++) {
      try {
        lock.lock();
        SUM += futures[tid].get();
        lock.unlock();
      } catch (InterruptedException | ExecutionException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Total sum is " + SUM);
  }

  static class Totalizator implements Callable<Long> {
    int tid;

    public Totalizator(int id) { tid = id; }

    public Long call() {
      long mysum = 0L;
      long stride = X / NUMBER_OF_THREADS;
      long left = tid * stride + 1;
      long right = tid * stride + stride;
      if (right > X)
        right = X;
      for (long i = left; i <= right; i++) {
        mysum += i;
      }
      System.out.printf("Sum computed by thread %d is %d\n", tid, mysum);
      return mysum;
    }
  }
}

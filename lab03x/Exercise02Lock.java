import java.util.concurrent.locks.ReentrantLock;

public class Exercise02Lock {
  static ReentrantLock lock = new ReentrantLock();
  static long SUM = 0;
  static long X;
  static int NUMBER_OF_THREADS;

  public static void main(String[] args) {
    if (args.length == 0) {
      X = 10_000_000;
      NUMBER_OF_THREADS = 4;
    } else {
      X = Long.parseLong(args[0]);
      NUMBER_OF_THREADS = Integer.parseInt(args[1]);
    }
    Thread threads[] = new Thread[NUMBER_OF_THREADS];
    for (int tid = 0; tid < threads.length; tid++) {
      threads[tid] = new TotalizatorThread(tid);
      threads[tid].start();
    }

    for (int tid = 0; tid < threads.length; tid++) {
      try {
        threads[tid].join();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
    System.out.println("Total sum is " + SUM);
  }

  static class TotalizatorThread extends Thread {
    int tid;

    public TotalizatorThread(int id) { tid = id; }

    public void run() {
      long mysum = 0L;
      long stride = X / NUMBER_OF_THREADS;
      long left = tid * stride + 1;
      long right = tid * stride + stride;
      if (right > X)
        right = X;
      for (long i = left; i <= right; i++) {
        mysum += i;
      }
      lock.lock(); 
      SUM += mysum; 
      lock.unlock();
      System.out.printf("Sum computed by thread %d is %d\n", tid, mysum);
    }
  }
}

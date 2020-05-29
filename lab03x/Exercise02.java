public class Exercise02 {
  static Object lock = new Object();
  static long MAX = 0;
  static long A[]={1,7,3,2,5,1,3,7,8,2}; 
  static long X=10;
  static int NUMBER_OF_THREADS=2;

  public static void main(String[] args) {
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
    System.out.println("Max is " + MAX);
  }

  static class TotalizatorThread extends Thread {
    int tid;

    public TotalizatorThread(int id) { tid = id; }

    public void run() {
      long mymax = 0L;
      long stride = X / NUMBER_OF_THREADS;
      long left = tid * stride;
      long right = tid * stride + stride;
      if (right > X)
        right = X;
      for (long i = left; i < right; i++) {
          if (A[(int)i]>mymax)
            mymax = A[(int)i];
      }
      synchronized (lock) { 
          if (mymax > MAX){
              MAX=mymax;
          }
       }
      System.out.printf("max computed by thread %d is %d\n", tid, mymax);
    }
  }
}

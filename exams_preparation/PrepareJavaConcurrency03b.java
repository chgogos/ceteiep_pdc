import java.util.Random;

public class PrepareJavaConcurrency03b implements Runnable {

    final static int T = 5;
    static int order = T - 1;

    int tid;

    public PrepareJavaConcurrency03b(int tid) {
        this.tid = tid;
    }

    public void run() {
        while (tid != order)
            ;
        System.out.print(tid);
        order--;
    }

    public static void main(String[] args) throws InterruptedException {
        Thread myThreads[] = new Thread[T];
        for (int t = 0; t < T; t++) {
            myThreads[t] = new Thread(new PrepareJavaConcurrency03b(t));
            myThreads[t].start();
        }
        for (int t = 0; t < T; t++)
            myThreads[t].join();
    }
}

/*
 * 43210
 */
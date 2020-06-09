import java.util.Random;

public class PrepareJavaConcurrency03a extends Thread {

    final static int T = 5;
    static int order = T - 1;

    int tid;

    public PrepareJavaConcurrency03a(int tid) {
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
            myThreads[t] = new PrepareJavaConcurrency03a(t);
            myThreads[t].start();
        }
        for (int t = 0; t < T; t++)
            myThreads[t].join();
    }
}



/*
 * 43210
 */
import java.util.Random;

public class PrepareJavaConcurrency03c {

    final static int T = 5;
    static int order = T - 1;

    public static void main(String[] args) throws InterruptedException {
        Thread myThreads[] = new Thread[T];
        for (int t = 0; t < T; t++) {
            myThreads[t] = new Thread(() -> {
                int tid = Integer.parseInt(Thread.currentThread().getName());
                while (tid != order)
                    ;
                System.out.print(tid);
                order--;
            }, String.valueOf(t)); 
            myThreads[t].start();
        }
        for (int i = 0; i < T; i++)
            myThreads[i].join();
    }
}

/*
43210
 */
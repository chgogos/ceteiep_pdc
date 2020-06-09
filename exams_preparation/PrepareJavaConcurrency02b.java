import java.util.Random;

public class PrepareJavaConcurrency02b {

    final static int N = 1_000_000;
    final static int T = 5;
    static double a[] = new double[N];
    static double b[] = new double[N];
    static double inner_prod = 0.0;
    static Object lock = new Object();

    public static void main(String[] args) throws InterruptedException {
        Random random = new Random(1729);
        for (int i = 0; i < N; i++) {
            a[i] = random.nextDouble();
            b[i] = random.nextDouble();
        }
        Thread myThreads[] = new Thread[T];
        for (int t = 0; t < T; t++) {
            myThreads[t] = new Thread(() -> {
                int tid = Integer.parseInt(Thread.currentThread().getName());
                double local_inner_product = 0.0;
                for (int i = tid * N / T; i < (tid + 1) * N / T; i++) {
                    local_inner_product += a[i] * b[i];
                }
                System.out.printf("Thread %s produced value %.2f\n", Thread.currentThread().getName(),
                        local_inner_product);
                synchronized (lock) {
                    inner_prod += local_inner_product;
                }
            }, String.valueOf(t)); // pass thread id (0,1,2,...)
            myThreads[t].start();
        }
        for (int i = 0; i < T; i++)
            myThreads[i].join();

        System.out.printf("Inner product: %.2f\n", inner_prod);
    }
}

/*
Thread 4 produced value 50112,41
Thread 1 produced value 50013,41
Thread 0 produced value 50226,71
Thread 2 produced value 50108,87
Thread 3 produced value 50132,94
Inner product: 250594,35
 */
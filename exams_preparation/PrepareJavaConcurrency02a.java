import java.util.Random;

public class PrepareJavaConcurrency02a {

    final static int N = 1_000_000;

    static double a[] = new double[N];
    static double b[] = new double[N];

    public static void main(String[] args) {
        Random random = new Random(1729);
        for (int i = 0; i < N; i++) {
            a[i] = random.nextDouble();
            b[i] = random.nextDouble();
        }

        double inner_prod = 0.0;
        for (int i = 0; i < N; i++) {
            inner_prod += a[i] * b[i];
        }

        System.out.printf("Inner product: %.2f\n", inner_prod);
    }
}

/*
Inner product: 250594,35
*/
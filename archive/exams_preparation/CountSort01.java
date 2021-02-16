import java.util.Random;
public class CountSort01 {
    final static int N = 10_000;
    static int a[] = new int[N];
    public static void main(String[] args) {
        Random random = new Random();
        for (int i = 0; i < N; i++) {
            a[i] = random.nextInt(2);
        }

        // κώδικας που ζητείται να παραλληλοποιηθεί (αρχή)
        int c = 0;
        for (int i = 0; i < N; i++)
            if (a[i] == 0)
                c++;
        // κώδικας που ζητείται να παραλληλοποιηθεί (τέλος)

        for (int i = 0; i < N; i++)
            if (i < c)
                a[i] = 0;
            else
                a[i] = 1;
        System.out.printf("The last 0 is at position %d\n", c - 1);
    }
}

/*
The last 0 is at position 5041
*/
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.Callable;
import java.util.concurrent.ThreadLocalRandom;

public class Exercise06TUI {

  static int NUMBER_OF_THREADS = 8;
  static int POINTS = 300_000_000;

  public static void main(String[] args)
      throws InterruptedException, ExecutionException {

    ExecutorService executor = Executors.newFixedThreadPool(NUMBER_OF_THREADS);
    List<Future<Integer>> futures = new ArrayList<>(NUMBER_OF_THREADS);
    int points_inside_circle[] = new int[NUMBER_OF_THREADS];

    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
      futures.add(
          executor.submit(new RandomPointThrower(POINTS / NUMBER_OF_THREADS)));
      points_inside_circle[i] = 0;
    }

    executor.shutdown();

    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
      points_inside_circle[i] = futures.get(i).get();
    }

    int sum = 0;

    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
      sum += points_inside_circle[i];
    }
    double pi = (double)sum / (double)POINTS * 4;
    System.out.printf("PI estimation: %.9f (error: %.5f%%)\n", pi,
                      Math.abs(pi - Math.PI) / Math.PI * 100);
  }

  static class RandomPointThrower implements Callable<Integer> {

    int number_of_points;

    public RandomPointThrower(int number_of_points) {
      this.number_of_points = number_of_points;
    }

    @Override
    public Integer call() throws Exception {
      int c = 0;
      for (int i = 0; i < number_of_points; i++) {
        double x = ThreadLocalRandom.current().nextDouble();
        double y = ThreadLocalRandom.current().nextDouble();
        x = x * 2 - 1;
        y = y * 2 - 1;
        double d = Math.sqrt(x * x + y * y);
        if (d < 1)
          c++;
      }
      return c;
    }
  }
}

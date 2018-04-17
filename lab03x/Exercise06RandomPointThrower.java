import java.util.concurrent.Callable;
import java.util.concurrent.ThreadLocalRandom;

public class Exercise06RandomPointThrower implements Callable<Integer> {

	int number_of_points;

	public Exercise06RandomPointThrower(int number_of_points) {
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

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class Exercise04Main {

	public static void main(String[] args) {
		BlockingQueue<Integer> buffer = new ArrayBlockingQueue<Integer>(10);
		Thread pt = new Thread(new Exercise04Producer(buffer, 20));
		Thread ct = new Thread(new Exercise04Consumer(buffer, 20));
		pt.start();
		ct.start();
	}

}

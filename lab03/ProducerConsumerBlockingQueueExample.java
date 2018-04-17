import java.util.concurrent.BlockingQueue;
import java.util.concurrent.SynchronousQueue;

public class ProducerConsumerBlockingQueueExample {
    public static void main(String[] args) {
        BlockingQueue<String> drop =
            new SynchronousQueue<String> ();
        (new Thread(new Producer2(drop))).start();
        (new Thread(new Consumer2(drop))).start();
    }
}
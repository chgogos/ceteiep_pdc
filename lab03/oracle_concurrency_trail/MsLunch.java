public class MsLunch {
    private long c1 = 0;
    private long c2 = 0;
    private Object lock1 = new Object();
    private Object lock2 = new Object();

    public void inc1() {
        synchronized(lock1) {
            c1++;
            // c2++;
        }
    }

    public void inc2() {
        synchronized(lock2) {
            c2++;
            // c1++;
        }
    }

    public void print(){
        System.out.printf("c1=%d c2=%d\n", c1, c2);
    }
}
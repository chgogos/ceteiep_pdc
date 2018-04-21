class Account {
  private long amount;
  public Account(long amount) { this.amount = amount; }
  void plus(long amount) { this.amount += amount; }
  void minus(long amount) {
    if (this.amount < amount)
      throw new IllegalArgumentException();
    else
      this.amount -= amount;
  }
  @Override
  public String toString() {
    return String.format("%d", amount);
  }

  static void transferWithDeadlock(long amount, Account first, Account second)
      throws InterruptedException {
    synchronized (first) {
      Thread.sleep(100);
      synchronized (second) {
        first.minus(amount);
        second.plus(amount);
      }
    }
  }
}

// NO DEADLOCK: locks are acquired at the same order
public class NoDeadlock {
  public static void main(String[] args) throws InterruptedException {
    final int T = 2;
    Account acc1 = new Account(1000);
    Account acc2 = new Account(1000);
    System.out.printf("Account1 %s - Account2 %s\n", acc1, acc2);

    Thread thread1 = new Thread(() -> {
      try {
        Account.transferWithDeadlock(50, acc1, acc2);
      } catch (InterruptedException ex) {
        ex.printStackTrace();
      }
    });
    Thread thread2 = new Thread(() -> {
      try {
        Account.transferWithDeadlock(50, acc1, acc2);
      } catch (InterruptedException ex) {
        ex.printStackTrace();
      }
    });
    
    thread1.start();
    thread2.start();

    thread1.join();
    thread2.join();
    System.out.printf("Account1 %s - Account2 %s\n", acc1, acc2);
  }
}

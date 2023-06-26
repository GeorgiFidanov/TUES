import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Chopstick {

    private final int id;
    private boolean isTaken;
    private final Lock lock;

    public Chopstick(int id) {
        this.id = id;
        isTaken = false;
        lock = new ReentrantLock();
    }

    public boolean pickUp() throws InterruptedException {
        if (lock.tryLock()) {
            isTaken = true;
            return true;
        }
        return false;
    }

    public void putDown() {
        isTaken = false;
        lock.unlock();
    }

    public int getId() {
        return id;
    }

    public boolean isTaken() {
        return isTaken;
    }
}

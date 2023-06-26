public class FutureResult<T> {
    private T result;
    private boolean resolved = false;

    public synchronized T await() {
        while (!resolved) {
            try {
                wait();
            } catch (InterruptedException e) {
                // Restore the interrupted status
                Thread.currentThread().interrupt();
            }
        }
        return result;
    }

    public synchronized void resolve(T result) {
        if (!resolved) {
            this.result = result;
            resolved = true;
            notifyAll();
        }
    }
}

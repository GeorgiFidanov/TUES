public class Main {
    public static void main(String[] args) {
        FutureResult<String> future = new FutureResult<>();

        new Thread(() -> {
            try {
                Thread.sleep(2000); // Simulate some long-running operation
                future.resolve("Result of the operation");
            } catch (InterruptedException e) {
                // Restore the interrupted status
                Thread.currentThread().interrupt();
            }
        }).start();

        System.out.println("Waiting for result...");
        String result = future.await();
        System.out.println("Result: " + result);
    }
}

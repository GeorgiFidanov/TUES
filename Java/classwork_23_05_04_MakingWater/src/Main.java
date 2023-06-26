public class Main {
    public static void main(String[] args) {
        Thread hydrogenGenerator = new Thread(() -> {
           while (true){
               new Hydrogen().start();
               try {
                   Thread.sleep(1000);
               } catch (InterruptedException e) {
                   throw new RuntimeException(e);
               }
           }
        });

        Thread oxygenGenerator = new Thread(() -> {
            while (true){
                new Oxygen().start();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        });

        hydrogenGenerator.start();
        oxygenGenerator.start();
        try {
            hydrogenGenerator.join();
            oxygenGenerator.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
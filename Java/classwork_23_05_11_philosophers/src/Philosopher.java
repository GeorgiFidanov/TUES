public class Philosopher extends Thread {

        private final int id;
        private final Chopstick leftChopstick;
        private final Chopstick rightChopstick;

        public Philosopher(int id, Chopstick leftChopstick, Chopstick rightChopstick) {
            this.id = id;
            this.leftChopstick = leftChopstick;
            this.rightChopstick = rightChopstick;
        }

        private void doActivity(String activity) throws InterruptedException {
            System.out.println("Philosopher " + id + " " + activity);
            Thread.sleep((int) (Math.random() * 100));
        }

        private void eat() throws InterruptedException {
            System.out.println("Philosopher " + id + " is eating");
            Thread.sleep((int) (Math.random() * 100));
        }

        public void run() {
            try {
                //noinspection InfiniteLoopStatement
                while (true) {
                    // Think
                    try {
                        doActivity("is thinking");
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    // Pick up left chopstick
                    while (true) {
                        try {
                            if (leftChopstick.pickUp()) break;
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                        try {
                            doActivity("is waiting to pick up left chopstick");
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                    }
                    System.out.println("Philosopher " + id + " picked up left chopstick " + leftChopstick.getId());
                    // Pick up right chopstick
                    while (true) {
                        try {
                            if (rightChopstick.pickUp()) break;
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                        try {
                            doActivity("is waiting to pick up right chopstick");
                        } catch (InterruptedException e) {
                            throw new RuntimeException(e);
                        }
                    }
                    System.out.println("Philosopher " + id + " picked up right chopstick " + rightChopstick.getId());
                    // Eat
                    try {
                        eat();
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                    // Put down right chopstick
                    rightChopstick.putDown();
                    System.out.println("Philosopher " + id + " put down right chopstick " + rightChopstick.getId());
                    // Put down left chopstick
                    leftChopstick.putDown();
                    System.out.println("Philosopher " + id + " put down right chopstick " + leftChopstick.getId());

                }
            } catch (RuntimeException e) {
                throw new RuntimeException(e);
            }
        }
}
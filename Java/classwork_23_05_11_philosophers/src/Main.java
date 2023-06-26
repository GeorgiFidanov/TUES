public class Main {

     public static void main(String[] args) {

         final int NUM_PHILOSOPHERS = 5;
         final int NUM_CHOPSTICKS = 5;

         // Create the chopsticks and philosophers
         Chopstick[] chopsticks = new Chopstick[NUM_CHOPSTICKS];
         for (int i = 0; i < NUM_CHOPSTICKS; i++) {
             chopsticks[i] = new Chopstick(i);
         }
         Philosopher[] philosophers = new Philosopher[NUM_PHILOSOPHERS];
         for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
             philosophers[i] = new Philosopher(i, chopsticks[i], chopsticks[(i+1)%NUM_CHOPSTICKS]);
         }
         // Start the philosophers
         for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
             philosophers[i].start();
         }
     }
}


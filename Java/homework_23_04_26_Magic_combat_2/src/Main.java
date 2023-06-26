import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a new game
        Game game = new Game(10, 20, 2, 2);

        // Start the game
        game.run();

        // Create a scanner to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Keep track of whether the game is over
        boolean gameOver = false;

        // Close the scanner
        scanner.close();
    }
}

import java.util.Random;

public class Game {
    private final Object[][] room;
    private final Player player;
    private final Enemy[] enemies;
    private final Item[] items;
    private final Chest[] chests;
    private final Random rand;

    public Game(int width, int height, int numZombies, int numSkeletons) {
        rand = new Random();

        // Initialize the room with walls and empty spaces
        room = new Object[height][width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
                    room[i][j] = "X"; // Wall
                } else {
                    room[i][j] = "O"; // Empty space
                }
            }
        }

        // Place the player in the bottom left corner
        player = new Player(100, new Inventory(), 10,10);
        room[height - 1][0] = "P";

        // Generate zombies and skeletons at random positions
        enemies = new Enemy[numZombies + numSkeletons];
        int index = 0;
        while (index < numZombies) {
            int x = rand.nextInt(width - 2) + 1; // Avoid placing on walls
            int y = rand.nextInt(height - 2) + 1;
            if (room[y][x].equals("O")) {
                enemies[index] = new Zombie(12,12);
                room[y][x] = "Z";
                index++;
            }
        }

        while (index < numZombies + numSkeletons) {
            int x = rand.nextInt(width - 2) + 1;
            int y = rand.nextInt(height - 2) + 1;
            if (room[y][x].equals("O")) {
                enemies[index] = new Skeleton(12,12);
                room[y][x] = "S";
                index++;
            }
        }

        // Generate items at random positions
        int numItems = rand.nextInt((int) (width * height * 0.1)) + 1;
        items = new Item[numItems];
        for (int i = 0; i < numItems; i++) {
            int x = rand.nextInt(width - 2) + 1;
            int y = rand.nextInt(height - 2) + 1;
            if (room[y][x].equals("O")) {
                room[y][x] = "I";
            }
        }

        // Generate chests at random positions
        int numChests = rand.nextInt(3);
        chests = new Chest[numChests];
        for (int i = 0; i < numChests; i++) {
            int x = rand.nextInt(width - 2) + 1;
            int y = rand.nextInt(height - 2) + 1;
            if (room[y][x].equals("O")) {
                chests[i] = new Chest();
                room[y][x] = "C";
            }
        }
    }

    public void run() {
        while (true) {
            // Print the room
            for (Object[] row : room) {
                for (Object cell : row) {
                    System.out.print(cell + " ");
                }
                System.out.println();
            }

            // Player's turn
            player.makeTurn(this);

            if (player.getHp() <= 0) {
                System.out.println("You died. Game over.");
                return;
            }

            // Enemies' turns
            for (Enemy enemy : enemies) {
                enemy.makeTurn(this, player);
                if (player.getHp() <= 0) {
                    System.out.println("You died. Game over.");
                    return;
                }
            }

            // Check if all enemies are defeated
            boolean allEnemiesDefeated = true;
            for (Enemy enemy : enemies) {
                if (enemy.isAlive()) {
                    allEnemiesDefeated = false;
                    break;
                }
            }
            if (allEnemiesDefeated) {
                System.out.println("Congratulations! You defeated all enemies and won the game!");
                return;
            }
        }
    }

    public Player[] getPlayer() {
        Player[] p1 = new Player[0];
        return p1;
    }

    public Enemy[] getEnemy() {
        Enemy[] enemies1 = new Enemy[0];
        return enemies1;
    }

    public boolean isGameOver() {
        return false;
    }
}

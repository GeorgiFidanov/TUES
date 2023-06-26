import java.util.Scanner;


public class Player {
    public int hp;
    public Inventory inventory;
    public int points;
    public int damage;

    public Player(int hp, Inventory inventory, int points, int damage) {
        this.hp = hp;
        this.inventory = inventory;
        this.points = points;
        this.damage = damage;
    }

    public void doAction(String action) {
        switch (action) {
            case "up" -> moveUp();
            case "down" -> moveDown();
            case "left" -> moveLeft();
            case "right" -> moveRight();
            case "attack" -> attack();
            case "use item" -> useItem();
           // case "equip" -> equip(item);
            case "sort" -> inventory.sort(this.getInventory());
            case "search" -> inventory.search(this.toString());
            //case "open" -> Chest ch.open(this,this);
            case "inv" -> inv();
            case "drop" -> inventory.drop(2);
            //case "end" -> end();
            default -> System.out.println("Invalid action.");
        }
    }

    private void end() {
    }

    private void useItem() {
    }

    private void attack() {
    }

    private void moveRight() {}

    private void moveLeft() {}

    private void moveDown() {}

    private void moveUp() {}

    public void makeTurn(Game game) {
        // Print player info
        System.out.println("Player health: " + hp);
        System.out.println("Player inventory: " + inventory);

        // Get user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter action: ");
        String action = scanner.nextLine();

        // Do action
        doAction(action);
    }


    public int getHp() {
        return hp;
    }

    public void setHp(int hp) {
        this.hp = hp;
    }

    public void setInventory(Inventory inventory) {
        this.inventory = inventory;
    }

    public void setPoints(int points) {
        this.points = points;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public Inventory getInventory() {
        return inventory;
    }

    public int getPoints() {
        return points;
    }

    public int getDamage() {
        return damage;
    }

    public void getHpBonus(int help) {
        setHp(getHp() + help);
    }

    public void inv(){
        for(Item item1 : inventory.items) {
            if (item1 instanceof ItemQuantity) {
                System.out.printf("%s, quantity: %d", item1.getName(), ((ItemQuantity) item1).getQuantity());
            } else {
                System.out.println(item1);
            }
        }
    }

    public void equip(Item item){
        for(Item item1 : inventory.items){
            if(item1.getName().equals(item.getName())){
                if (item1 instanceof ItemQuantity) {
                    if(item1 instanceof DamagePotion){
                        ((DamagePotion) item1).use(this,item);
                    }
                    if(item1 instanceof HealthPotion){
                        ((HealthPotion) item1).use(this);
                    }
                }
                if (item1 instanceof ItemDamage) {
                    if(item1 instanceof Bow){
                        ((Bow) item1).getDamage();
                    }
                    if(item1 instanceof Sword){
                        ((Sword) item1).getDamage();
                    }
                }
            }
        }
    }
}


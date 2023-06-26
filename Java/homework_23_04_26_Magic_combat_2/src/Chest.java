import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Chest {

    public List<Item> slot;

    public Chest() {slot = new ArrayList<>();}

    public void addItem(Item item) {
        if(slot.isEmpty()){
            slot.add(item);
        }
        else{
            throw new RuntimeException("Slot full");
        }
    }

    private void getRandomItem(){
        Random itemType = new Random();
        int number = itemType.nextInt(5);
        int quantity = itemType.nextInt(2, 10);
        int damage = itemType.nextInt(4, 15);

        switch (number) {
            case 0 -> addItem(new Arrow("arrow", quantity));
            case 1 -> addItem(new HealthPotion("health potion", quantity));
            case 2 -> addItem(new Sword("sword", damage));
            case 3 -> addItem(new Bow("bow", damage));
            case 4 -> addItem(new DamagePotion("damage potion", quantity));
        }
    }

    public void open(Chest chest, Player player){
        if(chest.slot.isEmpty()){
            throw new RuntimeException("Chest is empty");
        }
        else{
            chest.getRandomItem();
            player.inventory.addItem(chest.slot.get(0));
        }
    }
}


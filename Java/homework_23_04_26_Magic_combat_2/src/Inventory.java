import java.util.*;

public class Inventory {
    public List<Item> items;

    public Inventory() {
        items = new ArrayList<>();
    }

    public void addItem(Item item) {
        if (items.size() < 10) {
            for(Item item1 : items) {
                if (item1.getName().equals(item.getName())) {
                    if (item instanceof ItemQuantity && item1 instanceof ItemQuantity) {
                        ((ItemQuantity) item1).setQuantity(((ItemQuantity) item).getQuantity() + ((ItemQuantity) item1).getQuantity());
                    }
                    throw new RuntimeException("Inventory already has this");
                }
                items.add(item);
                System.out.println(items);
            }
        }else{
            throw new RuntimeException("Inventory is full");
        }
    }

    public void remove(Item item){
        for(Item item1 : items) {
            if(item1.getName().equals(item.getName())) {
                items.remove(item);
            }
        }
    }

    public void drop(int index){
        items.remove(items.get(index));
    }
    //filter
    public void search(String letter){
        for(Item item : items) {
            if(item.getName().startsWith(letter)) {
                System.out.println(item.getName());
            }
        }
    }

    public void sort(Inventory inventory) {
        inventory.sort(inventory);
    }
}


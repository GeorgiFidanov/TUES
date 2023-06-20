import java.util.HashSet;

public class Storage {
    public HashSet<Ingredient> ingredientQuantities;

    public Storage() {
        ingredientQuantities = new HashSet<>();
    }

    public void addToStorage(Ingredient item) {
        if (ingredientQuantities.contains(item)) {
            for (Ingredient existingItem : ingredientQuantities) {
                if (existingItem.getName().equals(item.getName())) {
                    existingItem.setQuantity(existingItem.getQuantity() + item.getQuantity());
                }
            }
        } else {
            Ingredient append = new Ingredient(item.getName(), item.getQuantity());
            ingredientQuantities.add(append);
        }
    }


    public void useIngredients(Ingredient item, int neededQuantity) {
        for (Ingredient existingItem : ingredientQuantities) {
            if (existingItem.getName().equals(item.getName())) {
                int availableQuantity = existingItem.getQuantity();
                if (availableQuantity >= neededQuantity) {
                    // Check ingredients availability
                    existingItem.setQuantity(availableQuantity - neededQuantity);
                } else {
                    throw new RuntimeException("Not enough ingrediant quantities");
                }
                break;
            }
        }
    }
}

import java.util.List;

public class Chef extends Employee {
    private final Storage storage;

    public Chef(String name, double salary, String designation, Storage storage) {
        super(name, salary, designation);
        this.storage = storage;
    }

    public void prepareOrder(Order order) {
        System.out.println("Chef " + this.getName() + " is preparing the order...");

        // Prepare the NON-doner
        List<FoodItem> foodItems = order.getFoodItems();
        for (FoodItem foodItem : foodItems) {
            String itemName = foodItem.getName();
            int requiredQuantity = foodItem.getCount();
            double price = foodItem.getPrice();
            order.setTotalPrice(order.getTotalPrice()+(price*requiredQuantity));
            System.out.println("Prepared " + requiredQuantity + " " + itemName);
        }

        //Prepare the doner
        DonerMenu doners = order.getDoners();
        for (DonerType doner : doners.donerTypes){
            String name = doner.getName();
            int quantity = doner.getCount();
            double price = doner.getPrice();
            List<Ingredient> items = doner.getIngredients();
            order.setTotalPrice(order.getTotalPrice()+(price*quantity));

            for(Ingredient item : items){
                Ingredient used = new Ingredient(item.getName(), item.getQuantity());
                storage.useIngredients(used, 1);
            }
            System.out.println("Prepared " + quantity + " " + name);
        }
        System.out.println("Order is ready!");
    }
}

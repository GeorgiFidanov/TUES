import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        // Create drink items
        DrinkItem coke = new DrinkItem("Coke", 1.5, 10);
        DrinkItem sprite = new DrinkItem("Sprite", 1.5, 8);
        if (coke.getName().equals("Coke")){
            System.out.println("We DON'T SALE COKE");
            coke.setName("Coca-Cola");
            coke.setPrice(coke.getPrice()*2);
            coke.increaseCount(1);
        }

        Ingredient majo = new Ingredient("Majo", 30);
        Ingredient tortilla = new Ingredient("Tortilla", 30);
        Ingredient hotSauce = new Ingredient("Hot Sauce", 30);
        Ingredient beef = new Ingredient("Beef", 15);
        Ingredient chicken = new Ingredient("Chicken", 15);
        Ingredient tomato = new Ingredient("Tomato", 30);
        Ingredient cucumber = new Ingredient("Cucumber", 30);
        Ingredient cabbage = new Ingredient("Cabbage", 30);
        Ingredient fries = new Ingredient("Fries", 60);
        Ingredient garlicSauce = new Ingredient("Garlic Sauce", 30);

        Storage Desk = new Storage();
        Desk.addToStorage(majo);
        Desk.addToStorage(tortilla);
        Desk.addToStorage(hotSauce);
        Desk.addToStorage(beef);
        Desk.addToStorage(chicken);
        Desk.addToStorage(tomato);
        Desk.addToStorage(cucumber);
        Desk.addToStorage(cabbage);
        Desk.addToStorage(fries);
        Desk.addToStorage(garlicSauce);

        //this is the default way a Beef Doner looks like:
        List<Ingredient> ingredientsForBeef = new ArrayList<>();
        ingredientsForBeef.add(majo);
        ingredientsForBeef.add(tortilla);
        ingredientsForBeef.add(tomato);
        ingredientsForBeef.add(fries);
        ingredientsForBeef.add(cucumber);
        ingredientsForBeef.add(beef);

        //this is the default way a Chicken Doner looks like:
        List<Ingredient> ingredientsForChicken = new ArrayList<>();
        ingredientsForChicken.add(hotSauce);
        ingredientsForChicken.add(chicken);
        ingredientsForChicken.add(cabbage);
        ingredientsForChicken.add(garlicSauce);
        ingredientsForChicken.add(tortilla);

        DonerType beefDoner = new DonerType("Beef Doner", 4.5, 2, ingredientsForBeef);
        DonerType chickenDoner = new DonerType("Chicken Doner", 4.0, 2, ingredientsForChicken);

        //modify the Doner how you like it
        beefDoner.addIngredients(cabbage);
        beefDoner.removeIngredients(tomato);
        if(!beefDoner.hasEnoughIngredients()){
            throw new RuntimeException("You made an empty Doner");
        }
        beefDoner.displayIngredients(beefDoner); //we see the abomination
        beefDoner.setName("Classic");


        // Create food items
        FoodItem falafel = new FoodItem("Falafel", 5.0, 3);
        falafel.decreaseCount(1); //one fell down
        falafel.increaseCount(1); // one was fried to restore the loss


        // Create user types
        UserType regularUser = new UserType("Regular User", "Standard user of the system");
        UserType premiumUser = new UserType("Premium User", "VIP user with exclusive benefits");
        regularUser.setName("Ivan"); //Ivan.
        regularUser.displayInfo();
        premiumUser.setDescription("Well-scammed");
        premiumUser.displayInfo();

        Customer customer = new Customer("John","rich",0,1000);
        customer.addToMoney(5);
        //make sure he pays with cache
        customer.setPaymentType(0);

        // Create employees
        Chef chef = new Chef("John Doe", 2500.0, "Chef", Desk);
        Employee waiter = new Employee("Jane Smith", 2000.0, "Waiter");
        if(waiter.getSalary() < 1000) {
            System.out.println("Salary:" + waiter.getSalary());
        }else if(waiter.getSalary() > 1000) {
            System.out.println("I will fix this, I am greedy");
            waiter.setSalary(999);
            System.out.println("Salary:" + waiter.getSalary());
        }

        DonerMenu Menu = new DonerMenu();
        Menu.addDonerType(beefDoner); //this is an official menu (no  bonus charge)
        Menu.addDonerType(chickenDoner);

        // Create an order
        Order order = new Order(customer);

        // Assign chef to the order
        order.assignChef(chef);

        // Add items to the order
        order.addDrinkItem(coke, 1);
        order.addDrinkItem(sprite, 1);
        order.addFoodItem(falafel, 1);
        order.addDoner(beefDoner,1);

        // Display the order details
        order.displayOrder();

        // Prepare the order
        order.prepareOrder();

        Map<Double, Integer> receipt = order.payment(customer);

        System.out.println("Total price:" + order.getTotalPrice());

        // Print the receipt
        System.out.println("Receipt:");
        for (Map.Entry<Double, Integer> entry : receipt.entrySet()) {
            double denomination = entry.getKey();
            int count = entry.getValue();
            System.out.println(denomination + " - " + count);
        }
    }
}
//link to diagram: https://app.diagrams.net/#G1W7ozD5reP4u4Ke1qcZo1BeNbQucnaQ_2
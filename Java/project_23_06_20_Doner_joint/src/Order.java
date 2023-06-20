import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

public class Order {
    private final List<DrinkItem> drinkItems;
    private final List<FoodItem> foodItems;
    public final DonerMenu doners;
    private final Customer customer;
    private double totalPrice;
    private Chef chef;

    public Order(Customer customer) {
        this.customer = customer;
        this.drinkItems = new ArrayList<>();
        this.foodItems = new ArrayList<>();
        this.doners = new DonerMenu();
        this.totalPrice = 0.0;
        this.chef = null;
    }

    // Methods to add items to the order

    public void addDrinkItem(DrinkItem drinkItem, int quantity_bought) {
        drinkItems.add(drinkItem);
        totalPrice += drinkItem.getPrice();
        drinkItem.decreaseCount(quantity_bought);
        drinkItem.displayInfo();
        System.out.println("Current total:" + getTotalPrice());
    }

    public void addFoodItem(FoodItem foodItem, int quantity_bought) {
        foodItems.add(foodItem);
        totalPrice += foodItem.getPrice();
        foodItem.decreaseCount(quantity_bought);
        System.out.println("Added NON-Doner, Current total:" + getTotalPrice());
    }

    public void addDoner(DonerType Doner, int quantity_bought) {
        doners.addDonerType(Doner);
        setTotalPrice(Doner.getPrice() + getTotalPrice() + 2);
        Doner.decreaseCount(quantity_bought);
        System.out.println("Added Doner, Current total:" + getTotalPrice());
    }

    // Getters and setters

    public List<DrinkItem> getDrinkItems() {
        return drinkItems;
    }

    public List<FoodItem> getFoodItems() {
        return foodItems;
    }

    public DonerMenu getDoners() {
        return doners;
    }

    public String getCustomerName() {
        return customer.getName();
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    public Chef getChef() {
        return chef;
    }

    // Additional methods

    public void assignChef(Chef chef) {
        this.chef = chef;
    } //set

    public void displayOrder() {
        System.out.println("Customer:" + getCustomerName());
        System.out.println("Drink Items:");
        for (DrinkItem drinkItem : getDrinkItems()) {
            drinkItem.displayInfo();
        }
        System.out.println("Food Items:");
        for (FoodItem foodItem : getFoodItems()) {
            foodItem.displayInfo();
        }
        System.out.println("Doners:");
        for (DonerType doner : doners.donerTypes) {
            DonerType curr = new DonerType(doner.getName(), doner.getPrice(),
                    doner.getCount(),doner.getIngredients());
            curr.displayInfo();
        }
        System.out.println("Total Price:" + getTotalPrice());

        if (chef != null) {
            System.out.println("Chef Assigned:" + getChef().getName());
        }
    }

    public void prepareOrder() {
        if (chef != null) {
            chef.prepareOrder(this);
        } else {
            System.out.println("No chef assigned to this order.");
        }
    }

    private boolean validateMoney(double value){
        return !(value < totalPrice);
    }

    public Map<Double, Integer> payment(Customer customer) {
        Map<Double, Integer> receipt = new HashMap<>();

        if (validateMoney(customer.getMoney())) {
            double change = customer.getMoney() - totalPrice;

            if (customer.getPaymentType() == 0) {
                System.out.println("Payment with cash selected");

                double[] denominations = { 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01 };

                for (double denomination : denominations) {
                    int count = (int) (change / denomination);
                    if (count > 0) {
                        receipt.put(denomination, count);
                        change %= denomination;
                    }
                }
            } else if (customer.getPaymentType() == 1) {
                System.out.println("Payment via card selected");
                customer.setMoney(customer.getMoney() - this.totalPrice);
            } else {
                throw new RuntimeException("Invalid payment type");
            }
        } else {
            throw new RuntimeException("Not enough money provided");
        }
        return receipt;
    }
}

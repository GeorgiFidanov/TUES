public class FoodItem {
    public final String name;
    public double price;
    public int count;

    public FoodItem(String name, double price, int count) {
        this.name = name;
        this.price = price;
        this.count = count;
    }

    // Getters and setters

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    // Additional methods

    public void increaseCount(int quantity) {
        setCount(getCount() + quantity);
    }

    public void decreaseCount(int quantity) {
        if (getCount() >= quantity) {
            setCount(getCount() - quantity);
        } else {
            throw new RuntimeException("Insufficient quantity available.");
        }
    }

    public void displayInfo() {
        System.out.println("Non-DONER food:" + getName());
        System.out.println("Price:" + getPrice());
        System.out.println("Available quantity:" + getCount());
    }
}

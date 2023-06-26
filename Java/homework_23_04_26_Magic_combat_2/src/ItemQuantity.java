public class ItemQuantity extends Item{
    public int quantity;
    public ItemQuantity(String name, int quantity) {
        super(name);
        this.quantity=quantity;
    }
    public int getQuantity() {
        return quantity;
    }
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}

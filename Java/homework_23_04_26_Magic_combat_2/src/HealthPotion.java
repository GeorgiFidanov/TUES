public class HealthPotion extends ItemQuantity {

    public HealthPotion(String name, int quantity) {
        super(name,quantity);
    }

    public void use(Player player) {
        int maxHp = 200;
        int bonus = 40;
        if(player.getHp()<maxHp){
            if(quantity > 0) {
                quantity = quantity - 1;
                player.setHp(player.getHp() + bonus);
                if (player.getHp() > maxHp) {
                    player.setHp(maxHp);
                }
            }
            if(quantity == 0){
                player.inventory.remove(this);
            }
        }
    }
}
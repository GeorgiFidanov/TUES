public class DamagePotion extends ItemQuantity {

    public DamagePotion(String name, int quantity) {
        super(name,quantity);
    }

    public void use(Player player, Item item) {
        int damageToWeapon = 2;
        if(quantity > 0) {
            quantity = quantity - 1;
            for (int i = 1; i < 4; i++) {
                if (item instanceof ItemDamage) {
                    ((ItemDamage) item).setDamage(((ItemDamage) item).getDamage() + damageToWeapon);
                }
            }
        }
        if(quantity == 0){
            player.inventory.remove(this);
        }
    }
}
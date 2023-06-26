public class ItemDamage extends Item{
    public int damage;
    public ItemDamage(String name, int damage) {
        super(name);
        this.damage=damage;
    }
    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }
}


public class Enemy{
    protected int hp;
    protected int damage;
    public Enemy(int hp, int damage){
        this.hp = hp;
        this.damage = damage;
    }

    public int getHp() {
        return hp;
    }

    public int getDamage() {
        return damage;
    }

    public void setHp(int hp) {
        this.hp = hp;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    void makeTurn(Game game, Player player) {
    }

    public boolean isAlive() {
        return getHp() > 0;
    }
}
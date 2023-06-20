import java.util.List;

public class DonerType extends FoodItem{
    private String name;
    private final List<Ingredient> ingredients;

    public DonerType(String name, double price, int count, List<Ingredient> ingredients) {
        super(name, price, count);
        this.ingredients = ingredients;
        this.name = name;

    }

    // Getters and setters

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Ingredient> getIngredients() {
        return ingredients;
    }

    public void addIngredients(Ingredient ingredient) {
        int checkpoint = 0;
        for (Ingredient curr : getIngredients()) { // if a doner is hot, but you want it extra hot
            if(curr.getName().equals(ingredient.getName())){
                curr.setQuantity(curr.getQuantity() + ingredient.getQuantity());
                checkpoint++;
                setPrice(getPrice()+2); // you pay extra
            }
        }
        if (checkpoint == 0){ //here you don't pay if you add new ingrediant that isn't already in
            this.ingredients.add(ingredient);
        }
    }

    public void removeIngredients(Ingredient ingredient) {
        int checkpoint = 0;
        for (Ingredient curr : this.getIngredients()) { // remove
            if(curr.getName().equals(ingredient.getName())){
                curr.setQuantity(0);
                checkpoint++;
                setPrice(getPrice()-0.5);
            }
        }
        if (checkpoint == 0){ //here you make a fool of yourself
            throw new RuntimeException("This ingredient even wasn't in the sandwich" + ingredient.getName());
        }
    }

    public boolean hasEnoughIngredients() {
        return !this.getIngredients().isEmpty();
    }

    public void displayIngredients(DonerType doner) {
        System.out.println("Ingredients for " + doner.getName());
        for (Ingredient ingredient : doner.getIngredients()) {
            if (ingredient.getQuantity() > 0){
                System.out.println(ingredient.getName());
            }
        }
    }
}

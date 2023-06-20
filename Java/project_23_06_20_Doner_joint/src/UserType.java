public class UserType {
    private String name;
    private String description;

    public UserType(String name, String description) {
        this.name = name;
        this.description = description;
    }

    // Getters and setters

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    // Additional methods

    public void displayInfo() {
        System.out.println("User Type:" + getName());
        System.out.println("Description: " + getDescription());
    }
}

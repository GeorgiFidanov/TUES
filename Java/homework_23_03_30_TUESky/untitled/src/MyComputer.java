import com.google.gson.Gson;

class MyComputer extends Computer {
    private String name;
    private int age;

    public MyComputer(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String toJSON() {
        Gson gson = new Gson();
        return gson.toJson(this);
    }

    public void printInheritedClassName() {
        System.out.println(this.getClass().getSuperclass().getName());
    }

    public void executeSecretFiles() {
        unlocked = true;
        secretFiles();
        unlocked = false;
    }
}
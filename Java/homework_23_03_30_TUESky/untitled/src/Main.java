public class Main {
    public static void main(String[] args) {
        MyComputer myComputer = new MyComputer("Name1", 10);
        System.out.println(myComputer.toJSON());
        myComputer.printInheritedClassName();
        myComputer.executeSecretFiles();
    }
}
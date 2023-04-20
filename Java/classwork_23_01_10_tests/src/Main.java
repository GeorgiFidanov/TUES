public class Main {
    public static void main(String[] args) throws InvalidValue, TooManyFiles  {
        System.out.println("Hello world!");
        User us1 = new User(4, "Steven");
        File<String> stringFile = new File<>("file1.txt", 4);
        stringFile.addContent("Hello world!!!!!");
        us1.addFile(stringFile);
        File file = us1.getFiles().get(0);

        System.out.println();
    }
}
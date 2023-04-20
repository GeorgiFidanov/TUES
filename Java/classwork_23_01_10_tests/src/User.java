import java.util.ArrayList;

public class User {
    private int age;
    private String username;

    private static int maxFiles = 3;
    private int fileCount;

    public int getAge() {
        return age;
    }

    public String getUsername() {
        return username;
    }

    private ArrayList<File> files;

    public ArrayList<File> getFiles() {
        return files;
    }

    public void addFile(File fl) throws TooManyFiles {
        if (fileCount+1 > maxFiles) throw new TooManyFiles();
        files.add(fl);
        fileCount++;
    }

    public boolean hasFile(File file){
        return files.contains(file);
    }

    public User(int age, String username) throws InvalidValue  {
        if (age <= 0) throw new InvalidValue();
        this.age = age;
        this.username = username;
        this.files = new ArrayList<>();
        fileCount = 0;
    }
}

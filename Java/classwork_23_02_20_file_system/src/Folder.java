import java.util.ArrayList;
import java.util.List;

public class Folder extends File {
    private String name;
    private List<File> content;

    public Folder(String name) {
        super();
        this.name = name;
        content = new ArrayList<>();
    }

    public void addFile(File file) {
        content.add(file);
    }
    public void addFolder(Folder folder) {
        content.add(folder);
    }

    public List<File> getContentFolder() {
        return content;
    }

    public String getName() {
        return name;
    }

    public String getSize() {
        int size = 0;
        for (File file : content) {
            size += Integer.parseInt(file.getSize());
        }
        return Integer.toString(size);
    }
}

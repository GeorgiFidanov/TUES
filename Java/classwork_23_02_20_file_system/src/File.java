public class File {
    private String name;
    private String content;

    public File(String name, String content) {
        this.name = name;
        this.content = content;
    }

    public File() {

    }

    public String getName() {
        return name;
    }

    public String getContentFile() {
        return content;
    }

    public String getSize() {
        return Integer.toString(content.length());
    }
}

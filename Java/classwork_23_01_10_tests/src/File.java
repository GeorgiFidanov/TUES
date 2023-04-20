public class File<T> {
    private String name;

    private int size;
    private T content;

    public T getContent() {
        return content;
    }

    public String getName() {
        return name;
    }

    public File(String name, int size) throws InvalidValue {
        this.name = name.toLowerCase();

        if (size < 0) throw new InvalidValue();
        this.size = size;
    }

    public void addContent(T content){
        this.content = content;
    }

    @Override
    public boolean equals(Object obj) {
        File<T> other = (File<T>)obj;

        return name.equals(other.name);
    }
}

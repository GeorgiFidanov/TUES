import java.util.List;

public class Main {
    public static void main(String[] args) {
        // create tree
        File file1 = new File("file1", "Hello, world!");
        File file2 = new File("File2", "This is a test file.");
        File file3 = new File("file3", "Another file with some content.");
        Folder folder1 = new Folder("folder1");
        Folder folder2 = new Folder("Folder2");
        Folder root = new Folder("root");

        folder1.addFile(file1);
        folder1.addFile(file2);
        folder2.addFile(file3);
        root.addFile(folder1);
        root.addFile(folder2);
        if(root.getContentFolder().isEmpty()) {
            root.addFolder(folder1);
        }
        if(file2.getContentFile().isEmpty()){
            System.out.println("Bad");
        }

        FileTree tree = new FileTree(root);
        tree.addChild(tree);

        // filter all files and folders that do not start with a capital letter
        List<Object> filteredList1 = FileTree.filterFiles(tree, node -> {
            if (node instanceof File) {
                return Character.isUpperCase(((File) node).getName().charAt(0));
            } else {
                return Character.isUpperCase(((Folder) node).getName().charAt(0));
            }
        });
        System.out.println("Files and folders that start with a capital letter:");
        for (Object node : filteredList1) {
            System.out.println("Name: " + ((node instanceof File) ? ((File) node).getName() : ((Folder) node).getName())
                    + ", Size: " + ((node instanceof File) ? ((File) node).getSize() : ((Folder) node).getSize()));
        }

        // filter all files and folders with a size less than 10
        List<Object> filteredList2 = FileTree.filterFiles(tree, node -> {
            if (node instanceof File) {
                return Integer.parseInt(((File) node).getSize()) < 10;
            } else {
                return Integer.parseInt(((Folder) node).getSize()) < 10;
            }
        });
        System.out.println("Files and folders with a size less than 10:");
        for (Object node : filteredList2) {
            System.out.println("Name: " + ((node instanceof File) ? ((File) node).getName() : ((Folder) node).getName())
                    + ", Size: " + ((node instanceof File) ? ((File) node).getSize() : ((Folder) node).getSize()));
        }

        // print the name and size of each file and folder
        FileTree.executeAction(tree, node -> {
            if (node instanceof File) {
                System.out.println("[File] Name: " + ((File) node).getName() + ", Size: " + ((File) node).getSize());
            } else {
                System.out.println("[Folder] Name: " + ((Folder) node).getName() + ", Size: " + ((Folder) node).getSize());
            }
        });

        // create a list of all files and folders, enclosed in square brackets
        StringBuilder stringBuilder = new StringBuilder();
        FileTree.executeAction(tree, node -> stringBuilder.append("[").append((node instanceof File) ? ((File) node).getName() : ((Folder) node).getName()).append("] "));
        System.out.println("List of all files and folders enclosed in square brackets: " + stringBuilder);
    }
}

import java.util.ArrayList;
import java.util.List;

public class FileTree {

    interface FilterLambda {
        boolean apply(Object node);
    }

    interface ActionLambda {
        void perform(Object node);
    }
    private Object node;
    private List<FileTree> children;

    public FileTree(Object node) {
        this.node = node;
        children = new ArrayList<>();
    }

    public void addChild(FileTree child) {
        children.add(child);
    }

    public Object getNode() {
        return node;
    }

    public List<FileTree> getChildren() {
        return children;
    }

    public static List<Object> filterFiles(FileTree tree, FilterLambda filter) {
        List<Object> filteredList = new ArrayList<>();

        if (filter.apply(tree.getNode())) {
            filteredList.add(tree.getNode());
        }

        for (FileTree child : tree.getChildren()) {
            filteredList.addAll(filterFiles(child, filter));
        }

        return filteredList;
    }

    public static void executeAction(FileTree tree, ActionLambda action) {
        action.perform(tree.getNode());

        for (FileTree child : tree.getChildren()) {
            executeAction(child, action);
        }
    }
}

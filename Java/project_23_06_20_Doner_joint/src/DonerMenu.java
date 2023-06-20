import java.util.ArrayList;
import java.util.List;

public class DonerMenu {
    public final List<DonerType> donerTypes;

    public DonerMenu() {
        this.donerTypes = new ArrayList<>();
    }

    public List<DonerType> getDonerTypes() {
        return donerTypes;
    }

    public boolean isDonerTypeAvailable(String donerTypeName) {
        for (DonerType donerType : getDonerTypes()) {
            if (donerType.getName().equals(donerTypeName)) {
                return false;
            }
        }
        return true;
    }
    public void addDonerType(DonerType doner) {
        if (isDonerTypeAvailable(doner.getName())) {
            donerTypes.add(doner);
            System.out.println("New type of Doner added to Menu.");
        }
        else{
            System.out.println("Doner "+ doner.getName() + "was already on the menu.");
        }
    }
}

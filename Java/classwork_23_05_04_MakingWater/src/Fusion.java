import java.util.List;

public class Fusion {
    private final static Fusion instance = new Fusion();

    private Fusion(){
    }

    public synchronized static boolean fuse(List<Atom> atoms) {
        int hydrogen = 0;
        int oxygen = 0;

        for(Atom at: atoms){
            if(at instanceof Hydrogen)
                hydrogen++;
            else if(at instanceof Oxygen)
                oxygen++;
        }

        if(hydrogen == 2 && oxygen == 1){
            for(Atom at: atoms){
                at.fuse(instance);
            }
            System.out.println("Successfully fused water!");
            return true;
        }
        else {
            System.out.println("Can't fuse " + hydrogen + " hydrogen and " + oxygen + " oxygen.");
            return false;
        }

    }
}

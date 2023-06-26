public class Atom extends Thread{
    private boolean hasBeenFused = false;

    public void fuse(Fusion fuser){
        hasBeenFused = true;
    }

    @Override
    public void run() {
        WaterFuser.passThrough(this);
        if(!hasBeenFused){
            System.out.println("Atom has passed through without being fused!!");
        }
    }
}

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Router extends Path{
    private String name;
    private String IP;
    private List<Router> neighbors;
    private ArrayList<Path> routes;

    private static int routeCounter = 0;

    private final static int MAX_ROUTE_ELEMENTS = 20;
    private final static int MAX_HOPS = 10;

    public Router(String name, String IP) {
        super();
        this.name = name;
        this.IP = IP;
        this.neighbors = new ArrayList<>();
        this.routes = new ArrayList<>();
    }

    public void add_router(Router router) {
        for (Router r : neighbors) {
            if (r.getName().equals(router.getName()) || r.getIP().equals(router.getIP())) {
                System.out.println("Router already exists");
                return;
            }
        }
        neighbors.add(router);
    }

    public boolean query_route(String address, int hop_count) {
        if (this.IP.equals(address)) {
            return true;
        }

        for (Path path : routes) {
            if (path.getIP().equals(address)) {
                return true;
            }
        }

        if (hop_count > 1) {
            for (Router neighbor : neighbors) {
                if (neighbor.query_route(address, hop_count - 1)) {
                    add_path(address, neighbors.indexOf(neighbor));
                    return true;
                }
            }
        }

        return false;
    }

    private void sortPaths() {
        routes = new ArrayList<>();
        Collections.sort(new ArrayList<>(),Collections.reverseOrder());
    }

    public void add_path(String IP, int index) {
        if (routes.size() > MAX_ROUTE_ELEMENTS) {
            routes.remove(routes.size() - 1);
            routes.add(new Path(IP, 0, index));

        } else {
            routes.add(new Path(IP, 0, index));
        }
    }

    public void send_package(NetworkPacket packet) {
        if (packet.getDst().equals(this.IP)) {
            System.out.println("Packet " + packet.getPacketID() + " received by " + this.name);

            routeCounter++;

            if(routeCounter == 10) {
                routeCounter = 0;
                sortPaths();
            }

            return;
        }

        for (Path route : routes) {
            if(!query_route(packet.getDst(), MAX_HOPS)) {
                System.out.println("No route found");
                return;
            }
            if (route.getIP().equals(packet.getDst())) {
                route.setPackets(route.getPackets() + 1);
                neighbors.get(route.getIndex()).send_package(packet);
                return;
            }
        }
    }

    public String getName() {
        return name;
    }

    @Override
    public String getIP() {
        return IP;
    }
}

import java.util.ArrayList;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        FileReader fr = new FileReader("file.txt");
        BufferedReader br = new BufferedReader(fr);
        String line;
        ArrayList<NetworkPacket> packets = new ArrayList<>();
        ArrayList<Router> routers = new ArrayList<>();
        while((line = br.readLine()) != null) {
            String[] values = line.split(" ");
            if (values[0].equals("packet")) {
                packets.add(new NetworkPacket(values[1], values[2], values[3]));
            } else if (values[0].equals("router")) {
                routers.add(new Router(values[1], values[2]));
            } else if (values[0].equals("packet_info")) {
                int packetId = Integer.parseInt(values[1]);
                for (NetworkPacket packet : packets) {
                    if (packet.getPacketID() == packetId) {
                        packet.addInfo(values[2], values[3]);
                        break;
                    }
                }
            }
        }
        br.close();
    }
}
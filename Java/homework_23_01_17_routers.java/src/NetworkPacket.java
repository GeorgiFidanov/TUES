import java.util.ArrayList;

public class NetworkPacket {
    private static int packet_count = 0;
    private final String content;
    private final String Src;
    private final String Dst;
    private final int packetID;
    private ArrayList<String> additionalInfo;

    public NetworkPacket(String content, String SRC, String DST) {
        if (content.isEmpty()) {
            throw new IllegalArgumentException("Packet can't be empty");
        }
        if (SRC.equals("0.0.0.0") || SRC.equals("127.0.0.0")) {
            throw new IllegalArgumentException("Invalid SRC address");
        }
        if (DST.equals("0.0.0.0") || DST.equals("127.0.0.0")) {
            throw new IllegalArgumentException("Invalid DST address");
        }
        this.content = content;
        this.Src = SRC;
        this.Dst = DST;
        this.packetID = ++packet_count;
        this.additionalInfo = new ArrayList<>();
    }

    public void addInfo(String info1, String info2) {
        additionalInfo.add(info1);
        additionalInfo.add(info2);
        //System.out.println("Additional information for packet with ID: " + packetID + " is: " + info1 + ", " + info2);
    }
    public String getContent() {
        return content;
    }

    public String getSrc() {
        return Src;
    }

    public String getDst() {
        return Dst;
    }

    public int getPacketID() {
        return packetID;
    }

    public ArrayList<String> getAdditionalInfo(){
        return additionalInfo;
    }
}
class Path {
    private String IP;
    private int packets;
    private int index;

    public Path(String IP, int packets, int index) {
        this.IP = IP;
        this.packets = packets;
        this.index = index;
    }

    public Path() {

    }

    public String getIP() {
        return IP;
    }

    public int getPackets() {
        return packets;
    }

    public int getIndex() {
        return index;
    }

    public void setPackets(int packets) {
        this.packets = packets;
    }
}

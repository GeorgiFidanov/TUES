class Computer {
    protected boolean unlocked = false;

    protected Computer() {}

    private void secretFiles() {
        if (unlocked) {
            System.out.println("Accessed secret files");
        }
    }
}






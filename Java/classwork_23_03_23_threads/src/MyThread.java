class MyThread implements Runnable {
    String name;
    Thread t;
    MyThread (String thread){
        name = thread;
        t = new Thread(this, name);
        System.out.println("New thread: " + t);
        t.start();
    }


    public void run() {
        try {
            int sum = 0;
            for(int i = 5; i > 0; i--){
                sum += 1;
                System.out.println(name + " extended the sum: " + sum);
                Thread.sleep(1000);
            }
        }
        /*try {
            for(int i = 5; i > 0; i--){
                System.out.println(name + " :" + i);
                Thread.sleep(1000);
            }
        }*/
        catch (InterruptedException e) {
            System.out.println(name + "Interrupted");
        }
        System.out.println(name + " exiting.");
    }
}



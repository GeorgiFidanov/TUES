public class Customer extends UserType{

    private int paymentType;
    private double money;
    public Customer(String name, String description, int paymentType, double money) {
        super(name, description);
        this.paymentType=paymentType;
        this.money=money;
    }

    public double getMoney() {
        return money;
    }

    public int getPaymentType() {
        return paymentType;
    }

    public void setPaymentType(int paymentType) {
        this.paymentType = paymentType;
    }

    public void setMoney(double money) {
        this.money = money;
    }
    private boolean validateValue(double value){

        double[] values = new double[]{100, 50, 20,10, 5, 2, 1,
                0.50, 0.20, 0.10, 0.05, 0.02, 0.01};

        for (double val : values) {
            if(val == value)
                return true;
        }

        return false;
    }
    public void addToMoney(double value){
        if(validateValue(value)){
            setMoney(getMoney()+value);
        }else{
            throw new ArithmeticException("Invalid money provided");
        }
    }
}

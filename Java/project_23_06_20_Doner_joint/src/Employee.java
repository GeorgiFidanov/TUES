public class Employee extends UserType{
    private double salary;

    public Employee(String name, double salary, String description) {
        super(name, description);
        this.salary = salary;
    }

    // Getters and setters

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    @Override
    public void displayInfo() {
        System.out.println("Employee Name: " + getName());
        System.out.println("Salary: $" + getSalary());
        System.out.println("Description: " + getDescription());
    }
}

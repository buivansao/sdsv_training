package ex.sds.employee;

// All sales have names
// Sales can be either male or female
// Each sale can have difference salary
// Sales can be either contracted or not contracted
public class Sales implements Employee {
    private String name, position, gender;
    private double salary;
    private boolean contracted;

    public Sales(String name, String position, String gender, double salary, boolean contracted) {
        setName(name);
        setPosition(position);
        setGender(gender);
        setSalary(salary);
        setContracted(contracted);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public void setContracted(boolean contracted) {
        this.contracted = contracted;
    }

    @Override
    public void work() {
        System.out.printf("%-20s%-20s%-20s%-20.1f%-20s\n", name, position, gender, salary, contracted);
    }

    @Override
    public boolean isFemale() {
        return gender.equals("female");
    }

    @Override
    public boolean isContracted() {
        return contracted;
    }

    @Override
    public double salary() {
        return salary;
    }
}

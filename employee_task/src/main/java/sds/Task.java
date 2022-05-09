package sds;

public class Task {
    private String name;
    private double value;

    public Task() {
        super();
    }

    public Task(String name, double value) {
        setName(name);
        setValue(value);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    @Override
    public String toString() {
        String s = ";" + name;
        if (value > 0) {
            s += ":" + value;
        }
        return s;
    }
}

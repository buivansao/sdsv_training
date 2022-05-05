package sds;

public class Employee {
    private int id;
    private String name, position;

    public Employee() {
        super();
    }
    public Employee(int id) {
        super();
        setId(id);
    }
    public Employee(int id, String name, String position) {
        super();
        setId(id);
        setName(name);
        setPosition(position);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPosition() {
        return position;
    }

    public void setPosition(String position) {
        this.position = position;
    }

    @Override
    public boolean equals(Object obj) {
        Employee employee = (Employee) obj;
        return id == employee.getId();
    }

    @Override
    public String toString() {
        return id + "; " + name + "; " + position;
    }
}

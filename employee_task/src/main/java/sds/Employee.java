package sds;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Employee {
    private String name;
    private List<Task> tasksDone = new ArrayList<Task>();
    private Scanner scanner = new Scanner(System.in);

    public Employee() {
        super();
    }

    public Employee(String name) {
        super();
        setName(name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void finishTask(Task task) {
        tasksDone.add(task);
    }

    public List<Task> getTasksDone() {
        return tasksDone;
    }

    public double totalValue() {
        double totalValue = 0.0;
        for (Task task : tasksDone) {
            totalValue += task.getValue();
        }

        return totalValue;
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        str.append(name);
        if (tasksDone.size() > 0) {
            for (Task task : tasksDone) {
                str.append(task.toString());
            }
        }

        return str.toString();
    }
}

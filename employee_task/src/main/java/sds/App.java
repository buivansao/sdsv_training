package sds;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        List<Employee> employees = new ArrayList<Employee>();

        Scanner scanner = new Scanner(System.in);
        int total = Integer.parseInt(scanner.nextLine());

        for (int i = 0; i < total; i++) {
            String line = scanner.nextLine();
            if (line.contains(";")) {
                String[] empData = line.split(";");
                Employee employee = new Employee(empData[0]);
                for (int j = 1; j < empData.length; j++) {
                    String[] taskData = empData[j].split(":");
                    if (taskData.length == 1) {
                        employee.finishTask(new Task(taskData[0], 0));
                    } else if (taskData.length == 2) {
                        employee.finishTask(new Task(taskData[0], Double.parseDouble(taskData[1])));
                    }
                }
                employees.add(employee);
            } else {
                employees.add(new Employee(line));
            }
        }

        System.out.println(total);
        for (Employee e : employees) {
            System.out.println(e.toString());
        }

        Employee bestEmp = employees.get(0);
        Employee worstEmp = employees.get(0);

        for (Employee e : employees) {
            if (employees.indexOf(e) == 0) {
                continue;
            }

            if (e.totalValue() > bestEmp.totalValue()) {
                bestEmp = e;
            }

            if (e.totalValue() < worstEmp.totalValue()) {
                worstEmp = e;
            }
        }

        System.out.println("BEST:" + bestEmp.getName() + "-" + bestEmp.totalValue() + "-" + bestEmp.getTasksDone().size());
        System.out.println("WORST:" + worstEmp.getName() + "-" + worstEmp.totalValue() + "-" + worstEmp.getTasksDone().size());
    }
}

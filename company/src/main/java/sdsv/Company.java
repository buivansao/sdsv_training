package sdsv;

import java.util.ArrayList;
import java.util.List;

public class Company {
    private String name;
    private double monthlyBudget;
    private double totalMoney = 0;
    private List<Employee> employees = new ArrayList<>();

    public Company(String name, double monthlyBudget) {
        super();
        this.setName(name);
        this.setMonthlyBudget(monthlyBudget);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getMonthlyBudget() {
        return monthlyBudget;
    }

    public void setMonthlyBudget(double monthlyBudget) {
        this.monthlyBudget = monthlyBudget;
    }

    public boolean addEmployee(Employee employee) {
        totalMoney += employee.getSalary();
        if (totalMoney <= monthlyBudget) {
            return employees.add(employee);
        }
        return false;
    }

    public void showInformation() {
        System.out.println("Company name: " + name + "; monthly budget: " + monthlyBudget + "\n");
        System.out.printf("%-20s%-20s\n", "Name", "Salary");
        for (Employee employee : employees) {
            System.out.printf("%-20s%-20f\n", employee.getName(), employee.getSalary());
        }
        System.out.print("\n");
    }

    public boolean removeEmployee(String name) {
        for (Employee employee : employees) {
            if (employee.getName().equals(name)) {
                return employees.remove(employee);
            }
        }
        return false;
    }

    public Employee getEmployee(String name) {
        for (Employee employee : employees) {
            if (employee.getName().equals(name)) {
                return employee;
            }
        }
        return null;
    }
}

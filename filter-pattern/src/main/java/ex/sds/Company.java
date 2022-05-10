package ex.sds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

import ex.sds.employee.*;
import ex.sds.filters.MaleCriterion;

public class Company {
    private final List<Employee> employees;
    private final MaleCriterion maleCriterion;

    public Company() {
        employees = new ArrayList<Employee>();
        maleCriterion = new MaleCriterion();
    }

    public void loadFromFile(String fileName) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(fileName));
        String line = reader.readLine();

        while (line != null) {
            String[] arrData = line.split(" ");

            switch (arrData[1]) {
                case "Sales":
                    employees.add(new Sales(arrData[0], arrData[1], arrData[2], Double.parseDouble(arrData[3]), Boolean.parseBoolean(arrData[4])));
                    break;
                case "Security":
                    employees.add(new Security(arrData[0], arrData[1], arrData[2], Double.parseDouble(arrData[3]), Boolean.parseBoolean(arrData[4])));
                    break;
                case "Receptionist":
                    employees.add(new Receptionist(arrData[0], arrData[1], arrData[2], Double.parseDouble(arrData[3]), Boolean.parseBoolean(arrData[4])));
                    break;
            }
            line = reader.readLine();
        }
        reader.close();
    }

    public void displayEmployees() {
        System.out.printf("%-20s%-20s%-20s%-20s%-20s\n", "Name", "Position", "Gender", "Salary", "Contract");
        for (Employee e : employees) {
            e.work();
        }
    }

    public void displayMaleEmployees() {
        System.out.printf("%-20s%-20s%-20s%-20s%-20s\n", "Name", "Position", "Gender", "Salary", "Contract");
        for (Employee e : getMaleEmployees()) {
            e.work();
        }
    }

    public void displaySecurityEmployees() {
        System.out.printf("%-20s%-20s%-20s%-20s%-20s\n", "Name", "Position", "Gender", "Salary", "Contract");
        for (Employee e : getSecurityEmployees()) {
            e.work();
        }
    }

    public List<Employee> getMaleEmployees() {
        return maleCriterion.match(employees);
    }

    public List<Employee> getSecurityEmployees() {
        return maleCriterion.securityEmployees(employees);
    }

    public List<Employee> getEmployees() {
        return employees;
    }
}

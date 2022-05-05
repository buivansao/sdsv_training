package sds;

import javafx.print.Printer;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Company {
    private List<Employee> employeeList = new ArrayList<Employee>();
    private String name;

    public Company() {
        super();
    }

    public Company(String name) {
        setName(name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void addEmployee(Employee employee) {
        employeeList.add(employee);
    }

    public boolean hasEmployee(int id) {
        return employeeList.contains(new Employee(id));
    }

    public Employee getEmployee(int id) {
        if (hasEmployee(id)) {
            return employeeList.get(employeeList.indexOf(new Employee(id)));
        }   
        return null;
    }

    public void saveToFile(String fName) throws FileNotFoundException {
        PrintWriter writer = new PrintWriter(new File(fName));
        for (Employee e : employeeList) {
            writer.println(e.toString());
        }
        writer.close();
    }

    public void loadFromFile(String fName) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(fName));
        String line = reader.readLine();
        while (line != null) {
            String[] data = line.split("; ");
            addEmployee(new Employee(Integer.parseInt(data[0]), data[1], data[2]));
            line = reader.readLine();
        }
        reader.close();
    }
}

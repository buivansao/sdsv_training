package ex.sds;

import java.util.List;

import ex.sds.employee.Employee;

public class App {
    public static void main(String[] args) throws Exception {
        Company company = new Company();
        company.loadFromFile("employees.txt");
        company.displayEmployees();

        System.out.println("------------------------------------------------------------\n");
        System.out.println("Male Employees\n");
        company.displayMaleEmployees();

        System.out.println("------------------------------------------------------------\n");
        System.out.println("Security Employees\n");
        company.displaySecurityEmployees();
    }
}

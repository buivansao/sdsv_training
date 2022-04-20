package sdsv;

import java.util.ArrayList;
import java.util.List;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        System.out.println("\nHello my friends ^_^\n");

        List<Company> companies = new ArrayList<>();
        companies.add(new Company("Sun*", 100));
        companies.add(new Company("VTI", 50));

        System.out.println("***1. Add companies and employees\n");
        for (Company company : companies) {
            for (int i = 0; i < 5; i++) {
                boolean flag = company.addEmployee(new Employee("Employee-" + i, 20));
                if (!flag) {
                    System.out.print("Company " + company.getName() + " does not have enough money -> ");
                    System.out.print("Employee-" + i + " can't be added\n");
                }
            }
        }

        System.out.println("\n***2. Show company information");
        for (Company company : companies) {
            company.showInformation();
        }

        System.out.println("\n***3. Get employee in all companies that match name");
        Employee employee;
        for (Company company : companies) {
            System.out.println("In company " + company.getName() + ": ");
            employee = company.getEmployee("Employee-0");
            if (employee != null) {
                System.out.printf("%-20s%-20f\n", employee.getName(), employee.getSalary());
            } else {
                System.out.print("Not found");
            }
        }

        System.out.println("\n***4. Remove employee in all companies that match name");
        for (Company company : companies) {
            if (company.removeEmployee("Employee-0")) {
                System.out.print("Removed Employee-0\n");
            } else {
                System.out.print("Not found\n");
            }
            company.showInformation();
        }
    }
}

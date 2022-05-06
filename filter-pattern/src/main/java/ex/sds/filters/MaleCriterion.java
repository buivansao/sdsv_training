package ex.sds.filters;

import java.util.ArrayList;
import java.util.List;

import ex.sds.employee.Employee;

public class MaleCriterion implements Criterion {
    @Override
    public List<Employee> match(List<Employee> employees) {
        List<Employee> maleEmployees = new ArrayList<Employee>();
        for (Employee e : employees) {
            if (!e.isFemale()) {
                maleEmployees.add(e);
            }
        }

        return maleEmployees;
    }

    public List<Employee> securityEmployees(List<Employee> employees) {
        List<Employee> securityEmployees = new ArrayList<Employee>();
        for (Employee e : employees) {
            if (e.getClass().getName().contains("Security")) {
                securityEmployees.add(e);
            }
        }

        return securityEmployees;
    }
}

package ex.sds.filters;

import java.util.List;

import ex.sds.employee.Employee;

public interface Criterion {
    public List<Employee> match(List<Employee> employees);
}
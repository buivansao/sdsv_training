package exam.sds;

import java.util.List;
import java.util.*;

class ListFullException extends Exception {
    public ListFullException() {
        super("ListFullException");
    }
}

class ToDo {
    private String task;
    private String when;

    public ToDo() {
        super();
    }

    public ToDo(String task) {
        super();
        setTask(task);
    }

    public ToDo(String task, String when) {
        super();
        setTask(task);
        setWhen(when);
    }

    public void setTask(String task) {
        this.task = task;
    }

    public String getTask() {
        return task;
    }

    public void setWhen(String when) {
        this.when = when;
    }

    public String getWhen() {
        return when;
    }

    @Override
    public boolean equals(Object obj) {
        ToDo toDo = (ToDo) obj;
        return task.equals(toDo.getTask());
    }
}

class ToDoList {
    private List<ToDo> thingsToDo;
    private int maxItems;

    public ToDoList() {
        super();
    }

    public ToDoList(int max) {
        super();
        setMaxItems(max);
        thingsToDo = new ArrayList<ToDo>();
    }

    public int getMaxItems() {
        return maxItems;
    }

    public void setMaxItems(int maxItems) {
        this.maxItems = maxItems;
    }

    public void add(String task, String when) throws ListFullException {
        if (thingsToDo.size() <= maxItems) {
            thingsToDo.add(new ToDo(task, when));
        } else {
            throw new ListFullException();
        }
    }

    public int where(String task) {
        return thingsToDo.indexOf(new ToDo(task));
    }

    public ToDo find(String task) {
        try {
            return thingsToDo.get(where(task));
        } catch (IndexOutOfBoundsException e) {
            return null;
        }
    }

    public int count() {
        return thingsToDo.size();
    }
}

public class App {
    public static void main(String[] args) throws ListFullException {
        ToDoList todoList = new ToDoList(5);
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            String[] data = sc.nextLine().split(" ");
            todoList.add(data[0], data[1]);
        }

        System.out.println(todoList.count() + " " + todoList.where("Study") + " " + todoList.find("Study").getTask());
    }
}

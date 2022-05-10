package exam.sds;

public class Balance {
    private String string;

    public Balance(String string) {
        setString(string);
    }

    public String getString() {
        return string;
    }

    public void setString(String string) {
        this.string = string;
    }

    public void print() {
        if (isBalance()) {
            System.out.println("String " + string + " is balance!");
        } else {
            System.out.println("String " + string + " is not balance!");
        }
    }

    private boolean isBalance() {
        if (!validate() || !isEvenLength()) {
            return false;
        }

        String[] leftStr = string.substring(0, countLength() / 2).split("");
        String[] rightStr = string.substring((countLength() / 2)).split("");
        int totalLeft = 0, totalRight = 0;

        for (int i = 0; i < leftStr.length; i++) {

        }
//        for (String s : leftStr) {
//            if (!s.equals(rightStr[--i])) {
//                return false;
//            }
//        }

        return true;
    }

    private int countLength() {
        return string.length();
    }

    private boolean isEvenLength() {
        return countLength() % 2 == 0;
    }

    private boolean validate() {
        return string.matches("^[(|)|{|}]+$");
    }
}

import java.util.Scanner;

public class ConvertString {
    private String targetString;
    private StringBuilder convertedString;

    public void insert() {
        Scanner s = new Scanner(System.in);
        System.out.print("Input string: ");
        targetString = s.nextLine();
    }

    public void show() {
        System.out.println("Converted string: " + convertedString.toString());
    }

    public void toCamelCase() {
        insert();

        String[] splitString = targetString.split("\\W+");
        convertedString = new StringBuilder();
        String tmpStr = null;

        for (int i = 0; i < splitString.length; i++) {
            convertedString.append(Character.toString(Character.toUpperCase(splitString[i].charAt(0))) + splitString[i].substring(1).toLowerCase());
        }

        show();
    }
}

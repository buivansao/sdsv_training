package exam.sds;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        List<String> strings = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLine()) {
            String line = sc.nextLine();
            if (line.indexOf("SDS 2022") > 0 && !(line.startsWith("#") || line.startsWith(";"))) {
                strings.add(line);
            }
        }

        for (String str : strings) {
            System.out.println(str);
        }
    }
}

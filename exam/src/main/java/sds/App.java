package sds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import org.json.JSONObject;

public class App 
{
    public static void main( String[] args ) throws IOException {
        System.out.println("Hello my friends ^_^\n");

        Exam exam = new Exam("Demo Examination");
        System.out.println(exam.getName() + "\n");

        System.out.println("*** LOAD QUESTIONS...\n");
        exam.loadQuestionsFromFile("questions.dat");
        exam.showQuestions();
        System.out.println("---------------------------------------------");

        System.out.println("*** TOTAL TIME & MAXIMUM POINT\n");
        exam.showExamPeriod();
        System.out.println("\nMaximum point: " + exam.getMaximumGrade());
        System.out.println("---------------------------------------------");

        System.out.println("\n*** LOAD ANSWERS...\n");
        BufferedReader reader = new BufferedReader(new FileReader("answers.dat"));
        String line = reader.readLine();
        Submission submission = new Submission();
        while (line != null) {
            JSONObject json = new JSONObject(line);
            submission.addAnswer(Integer.toString(json.getInt("questionId")), json.getString("answer"));
            line = reader.readLine();
        }
        reader.close();
        System.out.println("loaded answers successfully!\n");

        System.out.println("---------------------------------------------");
        System.out.println("*** EVALUATE\n");
        System.out.println("Total point: " + exam.evaluate(submission) + "\n");
    }
}

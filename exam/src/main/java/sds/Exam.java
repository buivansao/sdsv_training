package sds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import org.json.JSONObject;

public class Exam {
    private String name;
    private double totalPoint = 0;
    private List<Question> questions = new ArrayList<>();

    public Exam(String name) {
        super();
        setName(name);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getTotalPoint() {
        return totalPoint;
    }

    public void setTotalPoint(double totalPoint) {
        this.totalPoint = totalPoint;
    }

    public void showExamPeriod() {
        int totalTime = 0;
        for (Question question : questions) {
            totalTime += question.getMinutes();
        }

        int hours = totalTime / 60;
        int minutes = totalTime % 60;
        System.out.printf("Total time of exam: %dh%02dm", hours, minutes);
    }

    public void addQuestion(Question question) {
        questions.add(question);
    }

    public double getMaximumGrade() {
        double maxGrade = 0;
        for (Question question : questions) {
            maxGrade += question.getPoint();
        }
        return maxGrade;
    }

    public void loadQuestionsFromFile(String fName) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(fName));
        String line = reader.readLine();

        while (line != null) {
            JSONObject json = new JSONObject(line);

            if (json.getString("type").equals("CalculationQuestion")) {
                CalculationQuestion calculationQuestion = new CalculationQuestion();
                calculationQuestion.setQuestionId(json.getInt("questionId"));
                calculationQuestion.setPoint(json.getInt("point"));
                calculationQuestion.setMinutes(json.getInt("minutes"));
                calculationQuestion.setContent(json.getString("content"));
                calculationQuestion.setSolution(json.getString("solution"));

                addQuestion(calculationQuestion);
            } else {
                MultipleChoiceQuestion multipleChoiceQuestion = new MultipleChoiceQuestion();
                multipleChoiceQuestion.setOpt1(json.getString("opt1"));
                multipleChoiceQuestion.setOpt2(json.getString("opt2"));
                multipleChoiceQuestion.setOpt3(json.getString("opt3"));
                multipleChoiceQuestion.setOpt4(json.getString("opt4"));
                multipleChoiceQuestion.setQuestionId(json.getInt("questionId"));
                multipleChoiceQuestion.setPoint(json.getInt("point"));
                multipleChoiceQuestion.setMinutes(json.getInt("minutes"));
                multipleChoiceQuestion.setSolution(json.getString("solution"));

                addQuestion(multipleChoiceQuestion);
            }

            line = reader.readLine();
        }

        reader.close();
    }

    public void saveQuestionsToFile(String fName) {
        // TODO
    }

    public void showQuestions() throws IOException {
        for (Question question : questions) {
            question.viewQuestion();
            System.out.println();
        }
    }

    public double evaluate(Submission submission) {
        for (Question question : questions) {
            for (String i : submission.getSubmissions().keySet()) {
                if (question.getQuestionId() == Integer.parseInt(i) && submission.getSubmissions().get(i).equals(question.getSolution())) {
                    totalPoint += question.getPoint();
                }
            }
        }

        return totalPoint;
    }
}

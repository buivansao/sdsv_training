package sds;

import java.io.FileNotFoundException;
import java.io.IOException;

public abstract class Question {
    private double point, minutes;
    private int questionId;
    private String solution;

    public Question(double point, double minutes, int questionId) {
        super();
        setPoint(point);
        setMinutes(minutes);
        setQuestionId(questionId);
    }

    public Question() {
        super();
    }

    public double getPoint() {
        return point;
    }

    public void setPoint(double point) {
        this.point = point;
    }

    public double getMinutes() {
        return minutes;
    }

    public void setMinutes(double minutes) {
        this.minutes = minutes;
    }

    public int getQuestionId() {
        return questionId;
    }

    public void setQuestionId(int questionId) {
        this.questionId = questionId;
    }

    public String getSolution() {
        return solution;
    }

    public void setSolution(String solution) {
        this.solution = solution;
    }

    public abstract void viewQuestion() throws IOException;
    public abstract String toJson();

    public double evaluate(String answer) {
        // TODO
        return 0;
    }
}

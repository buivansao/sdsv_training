package sds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class Submission {
    private HashMap<String, String> submissions = new HashMap<String, String>();
    private String questionId, answer;

    public Submission() {
        super();
    }

    public Submission(String questionId, String answer) {
        super();
        setQuestionId(questionId);
        setAnswer(answer);
    }

    public String getQuestionId() {
        return questionId;
    }

    public void setQuestionId(String questionId) {
        this.questionId = questionId;
    }

    public String getAnswer() {
        return answer;
    }

    public void setAnswer(String answer) {
        this.answer = answer;
    }

    public HashMap<String, String> getSubmissions() {
        return submissions;
    }

    public void addAnswer(String questionId, String answer) throws IOException {
        submissions.put(questionId, answer);
    }

    public String getAnswer(String questionId) {
        return submissions.get(questionId);
    }
}

package sds;

public class CalculationQuestion extends Question {
    private String content;

    public CalculationQuestion() {
        super();
    }

    public CalculationQuestion(double point, double minutes, int questionId, String content) {
        super(point, minutes, questionId);
        setContent(content);
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public void viewQuestion() {
        System.out.printf("Question %d: %s\n", getQuestionId(), content);
    }

    @Override
    public String toJson() {
        // TODO
        return null;
    }
}

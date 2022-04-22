package sds;

public class MultipleChoiceQuestion extends Question {
    private String opt1, opt2, opt3, opt4;

    public MultipleChoiceQuestion() {
        super();
    }

    public MultipleChoiceQuestion(double point, double minutes, int questionId, String opt1, String opt2, String opt3, String opt4) {
        super(point, minutes, questionId);
        setOpt1(opt1);
        setOpt2(opt2);
        setOpt3(opt3);
        setOpt4(opt4);
    }

    public String getOpt1() {
        return opt1;
    }

    public void setOpt1(String opt1) {
        this.opt1 = opt1;
    }

    public String getOpt2() {
        return opt2;
    }

    public void setOpt2(String opt2) {
        this.opt2 = opt2;
    }

    public String getOpt3() {
        return opt3;
    }

    public void setOpt3(String opt3) {
        this.opt3 = opt3;
    }

    public String getOpt4() {
        return opt4;
    }

    public void setOpt4(String opt4) {
        this.opt4 = opt4;
    }

    @Override
    public void viewQuestion() {
        System.out.printf("Question %d: \n", getQuestionId());
        System.out.printf("%s\n%s\n%s\n%s\n", opt1, opt2, opt3, opt4);
    }

    @Override
    public String toJson() {
        // TODO
        return null;
    }
}

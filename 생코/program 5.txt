import java.util.*;

public class Prog4 {

    public static final int A = 91;
    public static final int AMINUS = 89;
    public static final int BPLUS = 87;
    public static final int B = 81;
    public static final int BMINUS = 79;
    public static final int CPLUS = 77;
    public static final int C = 71;
    public static final int CMINUS = 69;
    public static final int DPLUS = 67;
    public static final int D = 61;
    public static final int DMINUS = 55;
    public static final int F = 0;

    public static final String QUIZ = "QUIZ";
    public static final String LAB = "LAB";
    public static final String PROGRAM = "PROGRAM";
    public static final String EXAM = "EXAM";

    final static class Object {
        public double min,
        max,
        rawAvg,
        adjAvg,
        rawSD;

        public int    num;

        public String name;

        public Object(int num, double min, double max, double rawAvg, double adjAvg, double rawSD) {
            this.num = num;
            this.min = min;
            this.max = max;
            this.rawAvg = rawAvg;
            this.adjAvg = adjAvg;
            this.rawSD = rawSD;
        }
    }

    
    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);
        double[] scores = new double[1];

        //Enter weights of each
        System.out.print("Enter weights (quizzes, labs, programs, exams): ");
        int quizIntWeight = input.nextInt();
        int labIntWeight = input.nextInt();
        int programIntWeight = input.nextInt();
        int examIntWeight = input.nextInt();

        //Converts weight integers to doubles
        double quizWeight = (double)quizIntWeight / 100.00;
        double labWeight = (double)labIntWeight / 100.00;
        double programWeight = (double)programIntWeight / 100.00;
        double examWeight = (double)examIntWeight / 100.00;

        //Enter scores
        System.out.print("Enter maximum scores (quizzes, labs, programs, exams): ");
        double quizMaxScore = input.nextInt();
        double labMaxScore = input.nextInt();
        double programMaxScore = input.nextInt();
        double examMaxScore = input.nextInt();

        int quizNum = input(QUIZ, input);
        Object quiz = process(quizNum, scores, quizMaxScore, input);
        printQL(QUIZ, quiz);

        int labNum = input(LAB, input);
        Object lab = process(labNum, scores, labMaxScore, input);
        printQL(LAB, lab);

        int programNum = input(PROGRAM, input);
        Object program = process(programNum, scores, programMaxScore, input);
        printPE(PROGRAM, program);

        int examNum = input(EXAM, input);
        Object exam = process(examNum, scores, examMaxScore, input);
        printPE(EXAM, exam);

        finalPrint(quiz, quizWeight, lab, labWeight, program, programWeight, exam, examWeight);
    }

    public static void printQL(String name, Object obj) {
        System.out.println(name + " summary");
        System.out.println("-----------------------------");
        System.out.println("                         How many: " + obj.num);
        System.out.printf("                              Min: %.2f %n", obj.min);
        System.out.printf("                              Max: %.2f %n", obj.max);
        System.out.printf("                      Raw average: %.2f %n", obj.rawAvg);
        System.out.printf("                 Adjusted average: %.2f %n", obj.adjAvg);
        System.out.printf("           Raw standard deviation: %.2f %n", obj.rawSD);
        System.out.println("");
        System.out.println("");
    }

    public static void printPE(String name, Object obj) {
        System.out.println(name + " summary");
        System.out.println("-----------------------------");
        System.out.println("                         How many: " + obj.num);
        System.out.printf("                              Min: %.2f %n", obj.min);
        System.out.printf("                              Max: %.2f %n", obj.max);
        System.out.printf("                      Raw average: %.2f %n", obj.rawAvg);
        System.out.printf("           Raw standard deviation: %.2f %n", obj.rawSD);
        System.out.println("");
        System.out.println("");
    }

    public static int input(String name, Scanner input) {
        System.out.print("How many " + name + " scores? ");
        int num = input.nextInt();

        System.out.print("Enter " + name + " scores: ");  

        return num;
    }

    public static Object process(int num, double[] scores, double maxScore, Scanner input) { 
        double rawAvg = 0;
        double sum = 0;
        double rawMean = 0;
        int i;

        for (i = 0; i < num; i++) {
            scores = Arrays.copyOf(scores, scores.length + 1);
            scores[i] = input.nextDouble();
            sum = scores[i] + sum;
        }
        System.out.println("");

        //Calculate raw average
        rawAvg = sum / (maxScore * num);

        //Calculate rawMean && mean
        rawMean = sum / num;

        //Create variables
        double differences[] = new double[scores.length];

        //Calculate differences
        for (i = 0; i < num; i++) {
            differences[i] = (scores[i] - rawMean);
        }

        //Calculate differences squared
        for (i = 0; i < num; i++) {
            differences[i] = Math.pow(differences[i], 2);
        }

        //Reset sum
        sum = 0;

        //Calculate sum of squared differences
        for (i = 0; i < num; i++) {
            sum = differences[i] + sum;
        }

        //Calculate variance
        double variance;
        variance = sum / num;

        //Calculate raw standard deviation
        double rawSD = Math.sqrt(variance);

        //Calculate adjusted average
        double adjAvg = rawAvg + (maxScore / 100.00);

        //Sort array && calculate max and min
        Arrays.sort(scores);
        double min = scores[0];
        double max = scores[scores.length - 1]; 

        return new Object(num, min, max, rawAvg, adjAvg, rawSD);
    }

    public static void finalPrint(Object quiz, double quizWeight, Object lab, double labWeight, Object program, double programWeight, Object exam, double examWeight) {
        double finalAdjAvg = (quiz.adjAvg * quizWeight) + (lab.adjAvg * labWeight) + (exam.rawAvg * examWeight) + (program.rawAvg * programWeight);
        char finalGrade = ' ';
        char finalGradeMod = ' ';

        if (finalAdjAvg * 100 >= A) {
            finalGrade = 'A';
        } else 
        if (finalAdjAvg * 100 < A && finalAdjAvg * 100 >= AMINUS) {
            finalGrade = 'A';
            finalGradeMod = '-';
        }
        if (finalAdjAvg * 100 < AMINUS && finalAdjAvg * 100 >= BPLUS) {
            finalGrade = 'B';
            finalGradeMod = '+';
        } else
        if (finalAdjAvg * 100 < BPLUS && finalAdjAvg * 100 >= B) {
            finalGrade = 'B';
        } else
        if (finalAdjAvg * 100 < B && finalAdjAvg * 100 >= BMINUS) {
            finalGrade = 'B';
            finalGradeMod = '-';
        } else
        if (finalAdjAvg * 100 < BMINUS && finalAdjAvg * 100 >= CPLUS) {
            finalGrade = 'C';
            finalGradeMod = '+';
        } else
        if (finalAdjAvg * 100 < CPLUS && finalAdjAvg * 100 >= C) {
            finalGrade = 'C';
        } else
        if (finalAdjAvg * 100 < C && finalAdjAvg * 100 >= CMINUS) {
            finalGrade = 'C';
            finalGradeMod = '-';
        } else
        if (finalAdjAvg * 100 < CMINUS && finalAdjAvg * 100 >= DPLUS) {
            finalGrade = 'D';
            finalGradeMod = '+';
        } else 
        if (finalAdjAvg * 100 < DPLUS && finalAdjAvg * 100 >= D) {
            finalGrade = 'D';
        } else
        if (finalAdjAvg * 100 < D && finalAdjAvg * 100 >= DMINUS) {
            finalGrade = 'D';
            finalGradeMod = '-';
        } else
        if (finalAdjAvg * 100 < DMINUS && finalAdjAvg * 100 >= F) {
            finalGrade = 'F';
        }        

        System.out.printf("Final grade adjusted average: %.2f %n", finalAdjAvg);
        System.out.println("Final grade adjusted letter: " + finalGrade + finalGradeMod);
        System.out.println("");
        System.out.println("DONE. Normal termination.");

    }

}

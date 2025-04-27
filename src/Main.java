import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        //System.out.println("Введіть число");

        Scanner inputNoun = new Scanner(System.in);

        // З виразом 2x^2 - 4x + 5
        double[] coefficients = {2, -4, 5};

        Polynoma polynom = new Polynoma(coefficients);
        System.out.println("Поліном " + polynom);

        System.out.print("Введіть значення х - ");
        double x = inputNoun.nextDouble();

        //код далі
        double result = polynom.solving(x);
        System.out.println("Значення полінома, коли х = " + x + " Буде - " + result);
    }
}
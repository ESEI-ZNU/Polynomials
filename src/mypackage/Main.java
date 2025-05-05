package mypackage;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Scanner inputNoun = new Scanner(System.in); // Для вводу значення через консоль, використаємо
        //inputNoun - Назва

        System.out.println("Введіть кількість членів поліному: ");
        int numberOf = inputNoun.nextInt();

        // Створення массиву на numberOf елементів
        double[] coefficients = new double[numberOf];
        int[] degrees = new int[numberOf];

        for (int i = 0; i < numberOf; i++) {
            System.out.println("Введіть коефіцієнт для члена #" + (i + 1) + ":");
            coefficients[i] = inputNoun.nextDouble();
            System.out.println("Введіть ступінь для члена #" + (i + 1) + ":");
            degrees[i] = inputNoun.nextInt();
        }

        Polynomial polynom = new Polynomial(coefficients); //Створення об'єкту класу з конструктором
        System.out.println("Поліном " + polynom);

        System.out.print("Введіть значення х - ");
        double x = inputNoun.nextDouble(); // Запит на введення

        double result = polynom.solving(x); //Бере введене число х, та обраховує його з виразом.
        System.out.println("Значення полінома, коли х = " + x + " Буде - " + result);
    }
}


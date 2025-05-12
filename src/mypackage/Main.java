package mypackage;

import java.util.Scanner;

/**
 * Головний клас програми.
 */
public class Main {

    /**
     * Головний метод програми.
     *
     * @param args аргументи командного рядка
     */
    public static void main(String[] args) {
        Scanner inputNoun = new Scanner(System.in);

        // Введення ступеня полінома
        System.out.print("Введіть ступінь полінома: ");
        int degree = inputNoun.nextInt();

        // масив коефіцієнтів довжини degree+1
        int[] coefficients = new int[degree + 1];

        // Зчитуємо всі коефіцієнти
        for (int i = 0; i <= degree; i++) {
            System.out.print("Коефіцієнт при x^" + i + ": ");
            coefficients[i] = inputNoun.nextInt();
        }

        // об'єкт полінома
        Polynomial polynom = new Polynomial(coefficients);

        // Виводимо поліном у вигляді рядка
        System.out.println("Ваш поліном: " + polynom);

        // Зчитуємо значення x і обчислюємо
        System.out.print("Введіть значення x: ");
        int x = inputNoun.nextInt();
        int result = polynom.solving(x);

        // результат
        System.out.println("Результат: " + result);
    }
}

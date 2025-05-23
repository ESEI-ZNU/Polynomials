package mypackage;

import java.util.Scanner;

/**
 * Головний клас програми.
 * @author Роботягов Кирило
 * @version 1.0
 */
public class Main {

    /**
     * Головний метод програми.
     *
     * @param args Аргументи командного рядка
     */
    public static void main(String[] args) {
        Scanner inputNoun = new Scanner(System.in);

        while (true) {
            System.out.print("Введіть ступінь полінома: ");
            int degree = inputNoun.nextInt();

            /**
             * Масив коефіцієнтів довжини degree+1
             */
            int[] coefficients = new int[degree + 1];

            /**
             * Зчитуємо всі коефіцієнти
             */
            for (int i = 0; i <= degree; i++) {
                System.out.print("Коефіцієнт при x^" + i + ": ");
                coefficients[i] = inputNoun.nextInt();
            }

            /**
             * Об'єкт полінома
             */
            Polynomial polynom = new Polynomial(coefficients);

            /**
             * Виводимо поліном у вигляді рядка
             */
            System.out.println("Ваш поліном: " + polynom);

            /**
             * Вибір операції
             */
            System.out.println("Виберіть операцію над поліномом/поліномами:");
            System.out.println("0 - Розрахунок значення поліному");
            System.out.println("1 - Додавання двох поліномів");
            System.out.println("2 - Віднімання двох поліномів");
            System.out.println("3 - Множення поліному на одночлен");
            System.out.println("інакше - Вихід");

            /**
             * Зчитуємо вибір
             */
            int operation = inputNoun.nextInt();

            switch (operation) {
                case 0 -> {
                    /**
                     * Зчитуємо значення х і обчислюємо
                     */
                    System.out.print("Введіть значення х: ");
                    int x = inputNoun.nextInt();
                    int result = polynom.solving(x);
                    /**
                     * Результат
                     */
                    System.out.println("Результат: " + result);
                }
                default -> {
                    System.out.println("Вихід з програми");
                    System.exit(0);

                }
            }
        }
    }
}


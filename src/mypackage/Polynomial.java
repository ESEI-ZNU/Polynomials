package mypackage;

/**
 * Клас для роботи з поліномами.
 *
 * @author Роботягов Кирило
 * @version 1.0
 */
public class Polynomial {
    /**
     * Масив коефіцієнтів, індекс — ступінь.
     */
    private final int[] coefficients;

    // Конструктор
    public Polynomial(int[] coefficients) {
        this.coefficients = coefficients;
    }

    // Обчислення значення полінома
    public int solving(int x) {
        int result = 0;
        for (int i = 0; i < coefficients.length; i++) {
            result += coefficients[i] * (int)Math.pow(x, i);
        }
        return result;
    }

    // Вивід полінома як рядок
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = coefficients.length - 1; i >= 0; i--) {
            int coef = coefficients[i];
            if (coef == 0) continue;

            if (sb.length() > 0) {
                sb.append(coef > 0 ? " + " : " - ");
            } else if (coef < 0) {
                sb.append("-");
            }

            int absCoef = Math.abs(coef);
            if (absCoef != 1 || i == 0) {
                sb.append(absCoef);
            }

            if (i > 0) {
                sb.append("x");
                if (i > 1) {
                    sb.append("^").append(i);
                }
            }
        }
        return sb.toString();
    }
}

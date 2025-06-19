package mypackage;

/**
 * Клас, що представляє поліном.
 */
public class Polynomial {
    private int[] coefficients;

    /**
     * Конструктор
     * @param coefficients масив коефіцієнтів, де i-й елемент - це коефіцієнт при x^i
     */
    public Polynomial(int[] coefficients) {
        this.coefficients = coefficients;
    }

    /**
     * Повертає поліном у вигляді рядка
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = coefficients.length - 1; i >= 0; i--) {
            int coef = coefficients[i];
            if (coef != 0) {
                if (sb.length() > 0 && coef > 0) {
                    sb.append(" + ");
                } else if (coef < 0) {
                    sb.append(" - ");
                    coef = -coef;
                }
                if (i == 0 || coef != 1) {
                    sb.append(coef);
                }
                if (i > 0) {
                    sb.append("x");
                    if (i > 1) {
                        sb.append("^").append(i);
                    }
                }
            }
        }
        return sb.length() > 0 ? sb.toString() : "0";
    }

    /**
     * Обчислює значення полінома при заданому x
     */
    public int solving(int x) {
        int result = 0;
        int power = 1;
        for (int coef : coefficients) {
            result += coef * power;
            power *= x;
        }
        return result;
    }

    /**
     * Додавання двох поліномів
     */
    public Polynomial add(Polynomial other) {
        int maxLength = Math.max(this.coefficients.length, other.coefficients.length);
        int[] result = new int[maxLength];

        for (int i = 0; i < maxLength; i++) {
            int a = i < this.coefficients.length ? this.coefficients[i] : 0;
            int b = i < other.coefficients.length ? other.coefficients[i] : 0;
            result[i] = a + b;
        }
        return new Polynomial(result);
    }

    /**
     * Віднімання двох поліномів
     */
    public Polynomial subtract(Polynomial other) {
        int maxLength = Math.max(this.coefficients.length, other.coefficients.length);
        int[] result = new int[maxLength];

        for (int i = 0; i < maxLength; i++) {
            int a = i < this.coefficients.length ? this.coefficients[i] : 0;
            int b = i < other.coefficients.length ? other.coefficients[i] : 0;
            result[i] = a - b;
        }
        return new Polynomial(result);
    }

    /**
     * Розробник 2 — Множення полінома на одночлен
     */
    public Polynomial multiplyByMonomial(int coefficient, int exponent) {
        int[] result = new int[this.coefficients.length + exponent];

        for (int i = 0; i < this.coefficients.length; i++) {
            result[i + exponent] = this.coefficients[i] * coefficient;
        }
        return new Polynomial(result);
    }

    /**
     * Розробник 2 — Множення двох поліномів
     */
    public Polynomial multiply(Polynomial other) {
        int[] result = new int[this.coefficients.length + other.coefficients.length - 1];

        for (int i = 0; i < this.coefficients.length; i++) {
            for (int j = 0; j < other.coefficients.length; j++) {
                result[i + j] += this.coefficients[i] * other.coefficients[j];
            }
        }
        return new Polynomial(result);
    }
}

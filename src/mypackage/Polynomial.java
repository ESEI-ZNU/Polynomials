package mypackage;

/**
 * Клас для роботи з поліномами.
 *
 * @author Роботягов Кирило
 * @author Мелещенко Анжеліка
 * @version 1.1
 */
public class Polynomial {
    /**
     * Масив коефіцієнтів, індекс — ступінь.
     */
    private final int[] coefficients;

    /**
     * Конструктор
     * @param coefficients - Масив коефіцієнтів полінома, де індекс — це степінь, а значення — коефіцієнт
     */
    public Polynomial(int[] coefficients) {
        this.coefficients = coefficients;
    }



    /**
     * Розрахунок значення поліному
     *  @param x - Довільне значення користувача
     * @return - Значення поліному
     */

    public int solving(int x) {
        int result = 0;
        for (int i = 0; i < coefficients.length; i++) {
            result += coefficients[i] * (int)Math.pow(x, i);
        }
        return result;
    }

    /**
     * Вивід полінома як рядок
     */
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
    
 /**
     * Множення полінома на інший поліном.
     * @param other інший поліном
     * @return результат множення
     */
    public Polynomial multiply(Polynomial other) {
        Polynomial result = new Polynomial();

        for (Term thisTerm : this.terms) {
            // Множимо поліном other на кожен одночлен з this
            Polynomial temp = other.multiplyByMonomial(thisTerm);
            // Додаємо до результату
            result = result.add(temp);
        }

        return result;
    }

    /**
     * Ділення полінома на одночлен.
     * @param monomial одночлен, на який ділимо
     * @return результат ділення
     */
    public Polynomial divideByMonomial(Term monomial) {
        Polynomial result = new Polynomial();

        for (Term term : this.terms) {
            // Ділимо кожен одночлен полінома на заданий одночлен
            int newCoeff = term.getCoefficient() / monomial.getCoefficient();
            int newExp = term.getExponent() - monomial.getExponent();

            // Додаємо результат у новий поліном
            result.addTerm(new Term(newCoeff, newExp));
        }

        return result;
    }
    
    public Polynomial add(Polynomial secondPoly) {
        return secondPoly;
    }
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

}

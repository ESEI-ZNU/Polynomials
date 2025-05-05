package mypackage;

public class Polynomial {
    private final int[] degrees; //Ступінь
    private final double[] coefficients; //Коефіцієнти

    //Конструктор для ініціалізації об'єкта з корректними даними, зберігає коефіцієнти. Викликається один раз.

    public Polynoma(double[] coefficients, int[] degrees) {
        this.coefficients = coefficients;
        this.degrees = degrees;
    }

    //Для обчислення полінома
    public double solving(double x) {
        double result = 0;
        for (int i = 0; i < coefficients.length; i++) {
            result += coefficients[i] * Math.pow(x, degrees[i]);
        }
        return result;
    }

    //Для виведення поліному як рядок
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < coefficients.length; i++) {
            double coef = coefficients[i];
            int deg = degrees[i];

            if (coef == 0) continue;

            if (sb.length() > 0) {
                sb.append(coef > 0 ? " + " : " - ");
            } else if (coef < 0) {
                sb.append("-");
            }

            coef = Math.abs(coef);

            if (coef != 1 || deg == 0) {
                sb.append(coef);
            }

            if (deg > 0) {
                sb.append("x");
                if (deg > 1) {
                    sb.append("^").append(deg);
                }
            }
        }
        return sb.toString();
    }
}

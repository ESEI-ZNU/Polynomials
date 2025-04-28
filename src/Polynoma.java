public class Polynoma {

    private final int degree; //Ступінь полінома
    private final double[] coefficients; // Масив коефіцієнтів


    public Polynoma(double[] coefficients) {
        this.degree = coefficients.length - 1;// бо ступінь = n - 1
        this.coefficients = coefficients;
    }

    public double solving(double x) {
        double result = 0;
        int i;
        for (i = 0; i <= degree; i++) {
            result = result + coefficients[i] * Math.pow(x, degree - i); //Math pow ставить до степеня
        }
        return result;
    }

    //Для виведення поліному як рядок
    public String toString(){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i <= degree; i++) {
            double coef = coefficients[i];
            int stupin = degree - i;

            if (coef == 0) continue;

            if (!sb.isEmpty() && coef > 0) {
                sb.append(" + ");
            } else if (coef < 0) {
                sb.append(" - ");
                coef = - coef;
            }

            if (coef != 1 || stupin == 0) {
                sb.append(coef);
            }

            if (stupin > 0) {
                sb.append("x");
                if (stupin > 1) {
                    sb.append("^").append(stupin);
                }
            }
        }
        return sb.toString();
    }

}

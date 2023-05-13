#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double slope;
    double intercept;
} LinearRegression;

LinearRegression fit_linear_regression(double x[], double y[], int n)
{
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }
    double x_mean = sum_x / n;
    double y_mean = sum_y / n;
    double slope = (sum_xy - sum_x * y_mean) / (sum_xx - sum_x * x_mean);
    double intercept = y_mean - slope * x_mean;
    LinearRegression model = { slope, intercept };
    return model;
}

int main()
{
    double x[] = { 1, 2, 3, 4, 5 };
    double y[] = { 2, 4, 5, 4, 6 };
    int n = 5;

    LinearRegression model = fit_linear_regression(x, y, n);
    printf("Slope: %.2f\n", model.slope);
    printf("Intercept: %.2f\n", model.intercept);

    double new_x = 6;
    double new_y = model.intercept + model.slope * new_x;
    printf("Prediction for x=6: %.2f\n", new_y);

    return 0;
}

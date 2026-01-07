#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 1.0 / (1.0 + x * x);
}

int main()
{
    double a, b;
    int n;

    cout << "Enter lower limit a: ";
    cin >> a;

    cout << "Enter upper limit b: ";
    cin >> b;

    cout << "Enter number of intervals (even): ";
    cin >> n;

    if (n % 2 != 0)
    {
        cout << "Error: Number of intervals must be even!" << endl;
        return 0;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * f(x);
        else
            sum += 4 * f(x);
    }

    double integral = (h / 3.0) * sum;

    cout << "\nIntegral using Simpson's 1/3 Rule = "
         << fixed << setprecision(6) << integral << endl;

    return 0;
}

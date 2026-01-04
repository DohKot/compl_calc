#include <iostream>
#include <complex>
#include <cmath>
#define a 0.78539816339744
#define b 0.523598775598
using namespace std;
long double factorial(int N)
{
    if (N < 0)
    {
        return 0;
    }
    if (N == 0)
    {
        return 1;
    }
    long double result = 1;
    for (int i = 1; i <= N; i++)
    {
        result *= i;
    }
    return result;
}
double SH(double x)
{
    double res = 0;
    for (int i = 0; i < 20; i++)
    {
        res += pow(x, 2 * i + 1) / factorial(2 * i + 1);
    }
    return res;

}
double CH(double x)
{
    double res = 0;
    for (int i = 0; i < 20; i++)
    {
        res += pow(x, 2 * i) / factorial(2 * i);
    }
    return res;

}
long double C(double x)
{
    double res = 0.0;
    for (int n = 0; n < 20; ++n)
    {
        double term = pow(-1, n) * pow(x, 2 * n) / factorial(2 * n);
        res += term;
    }
    return res;
}

long double S(double x)
{
    double result = 0.0;
    for (int n = 0; n < 20; ++n)
    {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        result += term;
    }
    return result;
}
long double ReSINH(double x, double y)
{
    double res;
    res = SH(x) * C(y);
    return res;
}
long double ImSINH(double x, double y)
{
    double res;
    res = CH(x) * S(y);
    return res;
}
long double ReCOSH(double x, double y)
{
    double res;
    res = CH(x) * C(y);
    return res;
}
long double ImCOSH(double x, double y)
{
    double res;
    res = SH(x) * S(y);
    return res;
}
long double ReSIN(double x, double y)
{
    double res;
    res = S(x) * CH(y);
    return res;
}
long double ImSIN(double x, double y)
{
    double res;
    res = C(x) * CH(y);
    return res;
}
long double ReCOS(double x, double y)
{
    double res;
    res = - S(x) * SH(y);
    return res;
}
long double ImCOS(double x, double y)
{
    double res;
    res = C(x) * SH(y);
    return res;
}
int main()
{
    double c;
    double c_1;
    cin >> c;
    cin >> c_1;
    complex< double > z1(c, c_1);
    complex< double > z2(2.0, 1.0);
    complex <double> z3(0, 32.0);
    cout << z1 << endl;
    double res = ImSINH(z1.real(), z1.imag());
    double res_1 = ReSINH(z1.real(), z1.imag());
    cout << res_1 << "+(" << res << ")i" << endl;
    double res_2 = ImCOSH(z1.real(), z1.imag());
    double res_3 = ReCOSH(z1.real(), z1.imag());
    cout << res_3 << "+(" << res_2 << ")i" << endl;
    double res_4 = ImSIN(z1.real(), z1.imag());
    double res_5 = ReSIN(z1.real(), z1.imag());
    cout << res_5 << "+(" << res_4 << ")i" << endl;
    double res_6 = ImCOS(z1.real(), z1.imag());
    double res_7 = ReCOS(z1.real(), z1.imag());
    cout << res_7 << "+(" << res_6 << ")i" << endl;
    cout << z1 + z2 << endl; // Сложение комплексных чисел: (3, 3)
    cout << z1 - z2 << endl; // Разность комплексных чисел: (-1, 1)
    cout << z1 * z2 << endl; // Умножение комплексных чисел: (0, 5)
    cout << z1 / z2 << endl; // Деление комплексных чисел: (0.8, 0.6)
    cout << pow(z1, 2) << endl; // Возведение в степень комплексного числа: (-3, 4)
    cout << z3.real() << "+" << z3.imag() << "i" << endl;
    return 0;
}

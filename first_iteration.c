#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <locale.h>
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
    res = C(x) * CH(y);
    return res;
}
double complex COS(double complex z)
{
    long double re=creal(z);
    long double im=cimag(z);
    double complex res=ReCOS(re,im)*I+ImCOS(re,im);
    return res;
}
double complex SIN(double complex z)
{
    long double re=creal(z);
    long double im=cimag(z);
    double complex res=ReSIN(re,im)+ImSIN(re,im)*I;
    return res;
}
double complex SINH(double complex z)
{
    long double re=creal(z);
    long double im=cimag(z);
    double complex res=ReSINH(re,im)+ImSINH(re,im)*I;
    return res;
}
double complex COSH(double complex z)
{
    long double re=creal(z);
    long double im=cimag(z);
    double complex res=ReCOSH(re,im)+ImCOSH(re,im)*I;
    return res;
}
long double complex Esin(double complex z)
{
    double complex iz=-cimag(z)+creal(z)*I;
    double complex res = (cexp(iz)-cexp(-iz))/(2*I);
    return res;
}
double complex Ecos(double complex z)
{
    double complex iz=-cimag(z)+creal(z)*I;
    double complex res = (cexp(iz)+cexp(-iz))/(2);
    return res;
}
double complex Esinh(double complex z)
{
    double complex res_1=cexp(z);
    double complex res_2=cexp(-z);
    /*printf("%.5f + %.5fi\n", creal(res_1), cimag(res_1));
    printf("%.5f + %.5fi\n", creal(res_2), cimag(res_2));*/
    double complex res = (res_1-res_2)/2.0;
    return res;
}
double complex Ecosh(double complex z)
{
    double complex res_1=cexp(z);
    double complex res_2=cexp(-z);
    /*printf("%.5f + %.5fi\n", creal(res_1), cimag(res_1));
    printf("%.5f + %.5fi\n", creal(res_2), cimag(res_2));*/
    double complex res = (res_1+res_2)/2.0;
    return res;
}
double complex TANH(double complex z)
{
    double complex res = SINH(z)/COSH(z);
    return res;
}
double complex TAN(double complex z)
{

    double complex res = SIN(z)/COS(z);
    return res;
}
double complex CTG(ouble complex z)
{
    double complex res = COS(z)/SIN(z);
    return res;
}
double complex CTH(double complex z)
{
    double complez res = COSH(z)/SINH(z);
    return res;
}
int main()
{
    char *locale = setlocale(LC_ALL, "");
    double complex z;
    double real, imag;

    printf("Введите действительную и мнимую части комплексного числа: ");
    scanf("%lf %lf", &real, &imag);

    z = real + imag * I;

    printf("Комплексное число: %.2f + %.2fi\n", creal(z), cimag(z));
    /*double complex res = COS(z);
    double complex res_2 = SIN(z);
    double complex res_3 = COSH(z);
    double complex res_4 = SINH(z);
    printf("%.5f + %.5fi\n", creal(res), cimag(res));
    printf("%.5f + %.5fi\n", creal(res_2), cimag(res_2));
    printf("%.5f + %.5fi\n", creal(res_3), cimag(res_3));
    printf("%.5f + %.5fi\n", creal(res_4), cimag(res_4));
    printf("%.5f + %.5fi\n", creal(ccos(z)), cimag(ccos(z)));
    printf("%.5f + %.5fi\n", creal(csin(z)), cimag(csin(z)));
    printf("%.5f + %.5fi\n", creal(ccosh(z)), cimag(ccosh(z)));
    printf("%.5f + %.5fi\n", creal(csinh(z)), cimag(csinh(z)));*/
    double complex res = COS(z);
    double complex res_res=Ecos(z);
    double complex res_2 = SIN(z);
    long double complex res_2_1=Esin(z);
    double complex res_3 = COSH(z);
    double complex res_3_1 = Ecosh(z);
    double complex res_4 = SINH(z);
    double complex res_4_1=Esinh(z);
    printf("COS %.5f + %.5fi\n", creal(res), cimag(res));
    printf("ecos %.5f + %.5fi\n", creal(res_res), cimag(res_res));
    printf("SIN %.5f + %.5fi\n", creal(res_2), cimag(res_2));
    printf("Esin %.5f + %.5fi\n", creal(res_2_1), cimag(res_2_1));
    printf("COSH %.5f + %.5fi\n", creal(res_3), cimag(res_3));
    printf("ecosh %.5f + %.5fi\n", creal(res_3_1), cimag(res_3_1));
    printf("SINH %.5f + %.5fi\n", creal(res_4), cimag(res_4));
    printf("esinh %.5f + %.5fi\n", creal(res_4_1), cimag(res_4_1));
    printf("COS %.5f + %.5fi\n", creal(ccos(z)), cimag(ccos(z)));
    printf("SIN %.5f + %.5fi\n", creal(csin(z)), cimag(csin(z)));
    printf("COSH %.5f + %.5fi\n", creal(ccosh(z)), cimag(ccosh(z)));
    printf("SINH %.5f + %.5fi\n", creal(csinh(z)), cimag(csinh(z)));
    printf("real_imag exp %.5f + %.5fi\n", creal(cexp(z)), cimag(cexp(z)));
    printf("real_imag exp %.5f + %.5fi\n", creal(cexp(-z)), cimag(cexp(-z)));
    return 0;
}

#include<iostream>

using namespace std;

void VerstToKm()
{
    //10 000в = 10 668км
    constexpr double kmPerVerst = static_cast<double>(10000) / 10668;
    constexpr double verstPerKm = static_cast<double>(10668) / 10000;

    cout << 1000 << " km = " << 1000 * verstPerKm << " verses\n";
    cout << 1000 << " verse = " << 1000 * kmPerVerst << " km\n";
}

void KgToFunts()
{
    constexpr double kg_per_funt = 0.453592;
    double weight = 100;
    cout << weight << " kg = " << weight / kg_per_funt << " fonts\n";
    cout << weight << " fonts = " << weight * kg_per_funt << " kg\n";
}

void MilesToKm()
{
    //1mile = 1.6009km
    double kmPerMile = 1.6009;
    double milePerKg = 1 / 1.6009;

    cout << 1000 << " km = " << 1000 * milePerKg << " miles\n";
    cout << 1000 << " miles = " << 1000 * kmPerMile << " km\n";
}

double F(double x)
{
    return x * x;
};

void Integral()
{
    double S = 0, a = 1, b = 3;
    int N = 1000;
    double n = (b - a) / N;
    double x = a + n;

    while (x < b)
    {
        S = S + 4 * F(x);
        x += n;
        if (x >= b)
            break;
        S = S + 2 * F(x);
        x = x + n;
    }
    S = (n / 3) * (S + F(a) + F(b));
    std::cout << "Integral: " << S << "\n";
}

void Limit()
{
    int limit = 10;
    double sum = 0;

    for (int i = 0; i < limit; i++)
    {
        double x = static_cast<double>(i) / 10;
        sum += x;
    }
    std::cout << "Limit: " << sum << "\n";
}

void Circle()
{
    double r = 1;
    double pi = 3.14;
    double s = pi * r * r;
    double l = 2 * pi * r;
}

void Sphere()
{
    constexpr double r = 1;
    constexpr double pi = 3.14;
    double s = r * pi * r * 4;
    double v = (pi * 4 * r * r * r) / 3;
}

void Ring()
{
    constexpr double pi = 3.14;
    constexpr double r = 1;
    constexpr double R = 3;
    double s = ((R * R) - (r * r)) * pi;
    double l = R * pi * 2;
}

void Cylinder()
{
    double pi = 3.14;
    double r = 1;
    double h = 3;
    double side_S = (h * 2 * pi * r);
    double circle_S = 2 * pi * r * r;
    double V = pi * r * r * h;
    double S = circle_S + side_S;
}

void SexCylinder()
{
    double pi = 3.14;
    double r = 1;
    double R = 4;
    double h = 5;
    double side_S = 2 * pi * (R - r) * h;
    double circle_S = 2 * pi * r * r;
    double V = ((R * R - r * r) * pi * h);
    double S = circle_S + side_S;
}

void Rectangle()
{
    float a = 2, b = 3;
    float s = a * b;
    float p = (a + b) * 2;
}

void Cube()
{
    constexpr double a = 32;
    double s = a * a * 6;
    double p = a * 4 * 6;
    double v = a * a * a;
}

void Trapezoid()
{
    constexpr double a = 2;
    constexpr double b = 4;
    constexpr double h = 5;
    constexpr int c = static_cast<int>((b - a) / 2);

    double ob = sqrt(c * c + h * h);
    double s = (a + b) * h / 2;
    double p = (a + b + (ob * 2));
}

void Geometry()
{
    Circle();
    Sphere();
    Ring();
    Cylinder();
    SexCylinder();
    Rectangle();
    Cube();
    Trapezoid();
}

void CelsiumToFareingeit()
{
    constexpr double ci = 5 / 9;
    constexpr double co = 9 / 5;
    double c = 0;
    double f = (c * ci) + 32;
    c = (f - 32) * co;
}

int main()
{
    VerstToKm();
    KgToFunts();
    MilesToKm();
    CelsiumToFareingeit();
    Integral();
    Limit();
    Geometry();
    return 0;
}

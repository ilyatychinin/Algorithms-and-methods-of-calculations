#include <iostream>
#include <cmath>
#include <iomanip>

// �������, ������� ����� �������������
double f(double x) {
    return (1 / (5 - 4 * sin(x))) + x;
}

// ������� ��� ���������� ��������� ������� ���������������
double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double s = 0;
    for (int i = 1; i < n; i++) { // ��� ������ �������� � 1
        double x = a + i * h;
        s += h * f(x);
    }
    return s;
}
double middle_integrate(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = 0;
    for (int i = 0; i < n; i++) { // ��� ������ �������� � 1

        double x = a + i * h;
        //s += h * f(x);
        s += h * f(x + (h / 2));
    }
    return s;
}

int main() {
    setlocale(LC_ALL, "ru");

    double a, b, epsilon;
    int n;

    std::cout << "������� ������ ������ �������������� (a): ";
    std::cin >> a;
    std::cout << "������� ������� ������ �������������� (b): ";
    std::cin >> b;
    std::cout << "������� ��������� ���������� ������������� (n): ";
    std::cin >> n;
    std::cout << "������� ��������� �������� (epsilon): ";
    std::cin >> epsilon;

    double prev_result = 0, result = 0;

    // ���������� ��������� � ����������� n, ���� �� ��������� �������� epsilon
    do {
        prev_result = result;
        result = integrate(a, b, n);
        std::cout << "n = " << n << ", ��������� = " << std::setprecision(10) << result << std::endl;
        n *= 2; // ����������� ���������� ������������� � ��� ����
    } while (fabs(result - prev_result) > epsilon);

    // ����� �������������� ����������
    std::cout << "������������� ��������� ��������������: " << std::setprecision(10) << result << std::endl;
    std::cout << "���������� ������������� ��� ���������� ��������: " << n / 2 << std::endl;

    return 0;
}
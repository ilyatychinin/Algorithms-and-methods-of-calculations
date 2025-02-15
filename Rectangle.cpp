#include <iostream>
#include <cmath>
#include <iomanip>

// Функция, которую нужно интегрировать
double f(double x) {
    return (1 / (5 - 4 * sin(x))) + x;
}

// Функция для вычисления интеграла методом прямоугольников
double integrate(double a, double b, int n) {
    double h = (b - a) / n;
    double s = 0;
    for (int i = 1; i < n; i++) { // для правых начинать с 1
        double x = a + i * h;
        s += h * f(x);
    }
    return s;
}
double middle_integrate(double a, double b, int n)
{
    double h = (b - a) / n;
    double s = 0;
    for (int i = 0; i < n; i++) { // для правых начинать с 1

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

    std::cout << "Введите нижний предел интегрирования (a): ";
    std::cin >> a;
    std::cout << "Введите верхний предел интегрирования (b): ";
    std::cin >> b;
    std::cout << "Введите начальное количество подынтервалов (n): ";
    std::cin >> n;
    std::cout << "Введите требуемую точность (epsilon): ";
    std::cin >> epsilon;

    double prev_result = 0, result = 0;

    // Вычисление интеграла с увеличением n, пока не достигнем точности epsilon
    do {
        prev_result = result;
        result = integrate(a, b, n);
        std::cout << "n = " << n << ", Результат = " << std::setprecision(10) << result << std::endl;
        n *= 2; // Увеличиваем количество подынтервалов в два раза
    } while (fabs(result - prev_result) > epsilon);

    // Вывод окончательного результата
    std::cout << "Окончательный результат интегрирования: " << std::setprecision(10) << result << std::endl;
    std::cout << "Количество подынтервалов для достижения точности: " << n / 2 << std::endl;

    return 0;
}
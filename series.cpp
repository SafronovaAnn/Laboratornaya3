#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

// наибольший общий делитель
int64_t gcd(int64_t x, int64_t y) {
    while (y != 0) {
        int64_t t = y;
        y = x % y;
        x = t;
    }
    return x;
}

// сокращение дроби
void reduceFraction(int64_t& num, int64_t& den) {
    int64_t g = gcd(num, den);
    num /= g;
    den /= g;
}

// быстрое возведение в степень
int64_t power(int64_t base, int64_t exp) {
    int64_t res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}

int main() {
    int64_t a, b;

    cout << "Сумма бесконечного ряда\n";
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;

    if (b == 1) {
        cout << "infinity\n";
        return 0;
    }

    // вектор для конечных разностей
    vector<int64_t> diff(a + 2);
    for (int64_t i = 1; i <= a + 1; ++i) {
        diff[i] = power(i, a);
    }

    // вектор коэффициентов формулы Эйлера
    vector<int64_t> delta_A1(a + 1);
    delta_A1[0] = diff[1];

    // вычисляем конечные разности
    for (int64_t step = 1; step <= a; ++step) {
        for (int64_t i = 1; i <= a + 1 - step; ++i) {
            diff[i] = diff[i + 1] - diff[i];
        }
        delta_A1[step] = diff[1];
    }

    // числитель по формуле Эйлера
    int64_t num = 0;
    int64_t b_minus_1 = b - 1;

    for (int64_t k = 0; k <= a; ++k) {
        num += delta_A1[k] * power(b_minus_1, a - k);
    }

    // знаменатель
    int64_t den = power(b_minus_1, a + 1);

    // сокращаем дробь
    reduceFraction(num, den);

    // вывод
    cout << "\nРезультат: " << num << "/" << den << "\n";

    return 0;
}

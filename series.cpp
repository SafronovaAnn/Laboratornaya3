#include <iostream>

#include <cmath>

#include <cstdint>

 

using namespace std;

 

// Функция для нахождения НОД (алгоритм Евклида)

int64_t gcd(int64_t x, int64_t y) {

    while (y != 0) {

        int64_t temp = y;

        y = x % y;

        x = temp;

    }

    return x;

}

 

// Функция для сокращения дроби

void reduceFraction(int64_t& numerator, int64_t& denominator) {

    int64_t g = gcd(abs(numerator), abs(denominator));

    numerator /= g;

    denominator /= g;

}

 

int main() {

    int a, b;

 

    cout << "Сумма бесконечного ряда: " << endl;

 

    cout << "\nВведите a: ";

    cin >> a;

    cout << "Введите b: ";

    cin >> b;

 

    if (a < 1 || a > 10 || b < 1 || b > 10) {

        cout << "Ошибка! a и b должны быть от 1 до 10" << endl;

        return 1;

    }

 

    // Если b = 1, ряд расходится

    if (b == 1) {

        cout << "\nРезультат: infinity" << endl;

        return 0;

    }

 

    int64_t numerator = 0;   // числитель

    int64_t denominator = 1; // знаменатель

 

    // Вычисляем числитель и знаменатель по формулам

    switch (a) {

    case 1:

        numerator = b;

        denominator = (b - 1) * (b - 1);

        break;

    case 2:

        numerator = b * (b + 1);

        denominator = (b - 1) * (b - 1) * (b - 1);

        break;

    case 3:

        numerator = b * (b * b + 4 * b + 1);

        denominator = (b - 1) * (b - 1) * (b - 1) * (b - 1);

        break;

    case 4:

        numerator = b * (b * b * b + 11 * b * b + 11 * b + 1);

        denominator = (b - 1) * (b - 1) * (b - 1) * (b - 1) * (b - 1);

        break;

    case 5:

        numerator = b * (b * b * b * b + 26 * b * b * b + 66 * b * b + 26 * b + 1);

        denominator = 1;

        for (int i = 0; i < 6; i++) denominator *= (b - 1);

        break;

    case 6:

        numerator = b * (b * b * b * b * b + 57 * b * b * b * b + 302 * b * b * b + 302 * b * b + 57 * b + 1);

        denominator = 1;

        for (int i = 0; i < 7; i++) denominator *= (b - 1);

        break;

    case 7:

        numerator = b * (b * b * b * b * b * b + 120 * b * b * b * b * b + 1191 * b * b * b * b + 2416 * b * b * b + 1191 * b * b + 120 * b + 1);

        denominator = 1;

        for (int i = 0; i < 8; i++) denominator *= (b - 1);

        break;

    case 8:

        numerator = b * (b * b * b * b * b * b * b + 247 * b * b * b * b * b * b + 4293 * b * b * b * b * b + 15619 * b * b * b * b + 15619 * b * b * b + 4293 * b * b + 247 * b + 1);

        denominator = 1;

        for (int i = 0; i < 9; i++) denominator *= (b - 1);

        break;

    case 9:

        numerator = b * (b * b * b * b * b * b * b * b + 502 * b * b * b * b * b * b * b + 14608 * b * b * b * b * b * b + 88234 * b * b * b * b * b + 15619 * b * b * b * b + 88234 * b * b * b + 14608 * b * b + 502 * b + 1);

        denominator = 1;

        for (int i = 0; i < 10; i++) denominator *= (b - 1);

        break;

    case 10:

        numerator = b * (b * b * b * b * b * b * b * b * b + 1013 * b * b * b * b * b * b * b * b + 47840 * b * b * b * b * b * b * b + 455192 * b * b * b * b * b * b + 1310354 * b * b * b * b * b + 1310354 * b * b * b * b + 455192 * b * b * b + 47840 * b * b + 1013 * b + 1);

        denominator = 1;

        for (int i = 0; i < 11; i++) denominator *= (b - 1);

        break;

    }

 

    // Сокращаем дробь

    reduceFraction(numerator, denominator);

 

    // Выводим результат в виде обыкновенной дроби

    cout << "\nРезультат: ";

    if (denominator == 1) {

        cout << numerator << "/1" << endl;

    }

    else {

        cout << numerator << "/" << denominator << endl;

    }

 

    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
int main() {
    int a, b;
    double eps;
    cout << "СУММА БЕСКОНЕЧНОГО РЯДА" << endl;
 
    cout << "\nВведите a (целое от 1 до 10): ";
    cin >> a;
    cout << "Введите b (целое от 1 до 10): ";
    cin >> b;
    cout << "Введите точность eps: ";
    cin >> eps;
 
    if (a < 1 || a > 10 || b < 1 || b > 10) {
        cout << "Ошибка! a и b должны быть от 1 до 10" << endl;
        return 1;
    }
 
    // Если b = 1, ряд расходится
    if (b == 1) {
        cout << "\nРезультат: infinity" << endl;
        return 0;
    }
 
    double sum = 0.0;
    double currentTerm;
    int n = 1;
 
    do {
        currentTerm = pow(n, a) / pow(b, n);
        sum += currentTerm;
        n++;
 
        if (n > 1000000) break;
 
    } while (currentTerm > eps);
 
    cout << fixed << setprecision(3);
    cout << "Сумма ряда: " << sum << endl;
    cout << "Количество итераций: " << n - 1 << endl;
 
    return 0;
}
 

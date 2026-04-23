#include <iostream>
#include <vector>
#include <iomanip>
#include <random>
#include <set>
 
using namespace std;
 
typedef __int128_t int128;
 
random_device rd;
mt19937_64 rng(rd());
 
long long modPow(long long a, long long b, long long n) {
    long long res = 1;
    int128 base = a % n;
    while (b > 0) {
        if (b % 2 == 1) res = (long long)((int128)res * base % n);
        base = (base * base) % n;
        b /= 2;
    }
    return res;
}
 
vector<long long> getFactors(long long m) {
    vector<long long> factors;
    long long d = m;
    for (long long i = 2; i * i <= d; i++) {
        if (d % i == 0) {
            factors.push_back(i);
            while (d % i == 0) d /= i;
        }
    }
    if (d > 1) factors.push_back(d);
    return factors;
}
 
// ПРОВЕРКА ПО СХЕМЕ (Задание 2)
bool checkByScheme(long long n) {
    if (n < 3) return n == 2;
    if (n % 2 == 0) return false;
    long long a = 2; 
    if (modPow(a, n - 1, n) != 1) return false;
    vector<long long> factors = getFactors(n - 1);
    for (long long q : factors) {
        if (modPow(a, (n - 1) / q, n) == 1) return false;
    }
    return true;
}
 
int main() {
    setlocale(LC_ALL, "Russian");
    
    int bits;
    cout << "Введите разрядность bits (4-31): ";
    cin >> bits;
 
    long long minValue = 1LL << (bits - 1);
    long long maxValue = (1LL << bits) - 1;
    long long maxOdds = (maxValue - minValue) / 2 + 1;
 
    cout << "\nРезультаты выполнения тестов" << endl;
    cout << "================================================================" << endl;
    cout << "  №  |     Число n     |   Результат   |  Отвергнуто " << endl;
    cout << "-----+-----------------+---------------+-------------" << endl;
 
    set<long long> used;
    int row = 1;
    int rejected = 0;
    int totalLimit = 0; // Защита от бесконечного цикла
 
    uniform_int_distribution<long long> dist(minValue, maxValue);
 
    while (row <= 10 && used.size() < maxOdds && totalLimit < 2000) {
        totalLimit++;
        long long n = dist(rng);
 
        // Если число четное или уже было - это ОТКАЗ
        if (n % 2 == 0 || used.count(n)) {
            rejected++;
            continue;
        }
 
        used.insert(n);
        bool isPrime = checkByScheme(n);
 
        // ВЫВОД (размеры подогнаны под шапку)
        cout << " " << left << setw(3) << row << " | " 
             << right << setw(15) << n << " | " 
             << "  " << left << setw(11) << (isPrime ? "true" : "false") << " | " 
             << right << setw(10) << rejected << endl;
 
        rejected = 0; // Сброс для следующей строки
        row++;
    }
 
    cout << "================================================================" << endl;
    if (row <= 10) {
        cout << "Инфо: для " << bits << " бит найдено строк: " << row - 1 << endl;
    }
 
    return 0;
}
 

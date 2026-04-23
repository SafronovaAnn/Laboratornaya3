#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
// Структура для хранения координат графика
struct Point {
    double x, y;
};
 
// Функция cofe: имитирует получение данных остывания
// В реальности здесь может быть закон Ньютона-Рихмана: T(t) = Tsr + (Tk - Tsr) * e^(-rt)
vector<Point> cofe(double Tk, double Tsr, double r, int n) {
    vector<Point> data;
    for (int i = 0; i < n; i++) {
        double t = i * 1.0; // время в минутах
        double temp = Tsr + (Tk - Tsr) * exp(-r * t);
        data.push_back({t, log(temp - Tsr)}); // Линеаризация для аппроксимации
    }
    return data;
}
 
// Функция aprox: вычисляет коэффициенты прямой y = ax + b (МНК)
void aprox(const vector<Point>& data, double& a, double& b) {
    int n = data.size();
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
 
    for (const auto& p : data) {
        sumX += p.x;
        sumY += p.y;
        sumXY += p.x * p.y;
        sumX2 += p.x * p.x;
    }
 
    // Формулы из твоей блок-схемы
    a = (n * sumXY - sumX * sumY) / (n * sumX2 - pow(sumX, 2));
    b = (sumY - a * sumX) / n;
}
 
// Функция korrel: коэффициент корреляции Пирсона
double korrel(const vector<Point>& data) {
    int n = data.size();
    double sumX = 0, sumY = 0;
    for (const auto& p : data) {
        sumX += p.x;
        sumY += p.y;
    }
    double avgX = sumX / n;
    double avgY = sumY / n;
 
    double num = 0, denX = 0, denY = 0;
    for (const auto& p : data) {
        num += (p.x - avgX) * (p.y - avgY);
        denX += pow(p.x - avgX, 2);
        denY += pow(p.y - avgY, 2);
    }
    return num / sqrt(denX * denY);
}
 
int main() {
    setlocale(LC_ALL, "Russian");
    double Tk, Tsr, r;
    int n = 10; // Количество точек замера
 
    cout << "Введите начальную температуру (Tk): "; cin >> Tk;
    cout << "Введите температуру среды (Tsr): "; cin >> Tsr;
    cout << "Введите коэффициент остывания (r): "; cin >> r;
 
    vector<Point> points = cofe(Tk, Tsr, r, n);
    
    double a, b;
    aprox(points, a, b);
    double k = korrel(points);
 
    cout << fixed << setprecision(4);
    cout << "\n=== РЕЗУЛЬТАТЫ ===" << endl;
    cout << "Коэффициент наклона a: " << a << endl;
    cout << "Свободный член b: " << b << endl;
    cout << "Коэфф. корреляции r: " << k << endl;
    cout << "Коэфф. детерминации R^2: " << pow(k, 2) << endl;
 
    return 0;
}

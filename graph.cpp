#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;
 
double function(double x) {
    if (x < -2.0) {
        // Левая ветвь: x < -2
        return -0.5 * x - 1.5;
    } else if (x > 2.0) {
        // Правая ветвь: x > 2
        return 0.5 * x - 1.5;
    } else {
        // Центральная ветвь: -2 < x < 2
        return 2.0 * cos(2.0 * x);
    }
}
 
bool isBreakPoint(double x) {
    const double eps = 1e-9;
    return fabs(x + 2.0) < eps || fabs(x - 2.0) < eps;
}
 
int main() {
    double x_start, x_end, dx;
    
    cout << "Введите  Xstart, Xend, dx: ";
    cin >> x_start >> x_end >> dx;
    
    cout << fixed << setprecision(4);
    cout << "\n   x     |    y\n";
    cout << "---------+---------\n";
    
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        if (isBreakPoint(x)) {
            cout << setw(8) << x << " |   разрыв\n";
        } else {
            double y = function(x);
            cout << setw(8) << x << " | " << setw(8) << y << "\n";
        }
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    cout << "УВЛЕКАТЕЛЬНАЯ ИГРА" << endl;
    
    int n, m;
    cout << "\nВведите n и m: ";
    cin >> n >> m;
    
    vector<int> a(n);
    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long scorePavel = 0;
    long long scoreVika = 0;
    
    int first = 0;
    int lastMove = 0;
    bool pavelTurn = true;
    
    while (first < n) {
        // Вычисляем префиксные суммы
        vector<long long> prefix(n - first + 1, 0);
        for (int i = first; i < n; i++) {
            prefix[i - first + 1] = prefix[i - first] + a[i];
        }
        
        int bestK = -1;
        long long bestSum = -1e18;
        
        // Ищем лучший ход
        for (int k = 1; k <= m && first + k <= n; k++) {
            // Нельзя брать столько же, сколько взял противник
            if (k == lastMove) continue;
            
            if (prefix[k] > bestSum) {
                bestSum = prefix[k];
                bestK = k;
            }
        }
        
        // Если все варианты запрещены, берём минимальное k (1)
        if (bestK == -1) {
            bestK = 1;
            bestSum = prefix[1];
        }
        
        // Применяем ход
        if (pavelTurn) {
            scorePavel += bestSum;
        } else {
            scoreVika += bestSum;
        }
        
        lastMove = bestK;
        first += bestK;
        pavelTurn = !pavelTurn;
    }
    
    // Вывод результата
    cout << "\nРезультат: ";
    if (scorePavel > scoreVika) {
        cout << 1 << " (Победил Павел)" << endl;
    } else {
        cout << 0 << " (Победила Вика)" << endl;
    }
    
    return 0;
}
 

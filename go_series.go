package main

import (
    "fmt"
    )

    // наибольший общий делитель
    func gcd(x, y int64) int64 {
    for y != 0 {
        x, y = y, x% y
    }
    return x
}

// сокращение дроби
func reduceFraction(num, den* int64) {
g: = gcd(*num, *den)
* num /= g
* den /= g
}

// быстрое возведение в степень
func power(base, exp int64) int64 {
res: = int64(1)
for exp > 0 {
    if exp % 2 == 1 {
        res *= base
    }
    base *= base
        exp /= 2
}
return res
}

func main() {
    var a, b int64

        fmt.Println("Сумма бесконечного ряда")
        fmt.Print("Введите a: ")
        fmt.Scan(&a)
        fmt.Print("Введите b: ")
        fmt.Scan(&b)

        if b == 1 {
            fmt.Println("infinity")
                return
        }

    // вектор для конечных разностей
diff: = make([]int64, a + 2)
for i : = int64(1); i <= a + 1; i++ {
    diff[i] = power(i, a)
}

// вектор коэффициентов формулы Эйлера
delta_A1: = make([]int64, a + 1)
delta_A1[0] = diff[1]

// вычисляем конечные разности
for step : = int64(1); step <= a; step++ {
    for i : = int64(1); i <= a + 1 - step; i++ {
        diff[i] = diff[i + 1] - diff[i]
    }
    delta_A1[step] = diff[1]
}

// числитель по формуле Эйлера
var num int64 = 0
b_minus_1 : = b - 1

for k : = int64(0); k <= a; k++ {
    num += delta_A1[k] * power(b_minus_1, a - k)
}

// знаменатель
den: = power(b_minus_1, a + 1)

// сокращаем дробь
reduceFraction(&num, &den)

// вывод
fmt.Printf("\nРезультат: %d/%d\n", num, den)
}

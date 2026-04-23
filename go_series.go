package main
 
import (
    "fmt"
    "math"
)
 
func main() {
    var a, b int
    var eps float64
 
    fmt.Println("СУММА БЕСКОНЕЧНОГО РЯДА")
 
    fmt.Print("\nВведите а (от 1 до 10): ")
    fmt.Scan(&a)
    fmt.Print("Введите b (от 1 до 10): ")
    fmt.Scan(&b)
    fmt.Print("Введите точность eps: ")
    fmt.Scan(&eps)
 
    // Проверка ввода
    if a < 1 || a > 10 || b < 1 || b > 10 {
        fmt.Println("Ошибка! а и b должны быть от 1 до 10")
        return
    }
 
    // Если b = 1, ряд расходится
    if b == 1 {
        fmt.Println("\nРезультат: infinity")
        return
    }
 
    sum := 0.0
    var term float64
    n := 1
 
    for {
        // Вычисляем n^a и b^n с помощью math.Pow
        term = math.Pow(float64(n), float64(a)) / math.Pow(float64(b), float64(n))
        sum += term
        n++
 
        // Защита от бесконечного цикла
        if n > 1000 {
            break
        }
 
        // Выходим, когда член стал меньше точности
        if term < eps {
            break
        }
    }
 
    fmt.Printf("\nСумма ряда: %.3f\n", sum)
    fmt.Printf("Количество итераций: %d\n", n-1)
}

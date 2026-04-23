package main
 
import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)
 
func main() {
    reader := bufio.NewReader(os.Stdin)
 
    fmt.Println("УВЛЕКАТЕЛЬНАЯ ИГРА")
    fmt.Print("\nВведите n и m: ")
    line, _ := reader.ReadString('\n')
    parts := strings.Fields(line)
    n, _ := strconv.Atoi(parts[0])
    m, _ := strconv.Atoi(parts[1])
 
    fmt.Printf("Введите %d чисел: ", n)
    line, _ = reader.ReadString('\n')
    parts = strings.Fields(line)
 
    a := make([]int, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(parts[i])
    }
 
    var scorePavel, scoreVika int64
    first := 0
    lastMove := 0
    pavelTurn := true
 
    for first < n {
        // Вычисляем префиксные суммы
        prefix := make([]int64, n-first+1)
        for i := first; i < n; i++ {
            prefix[i-first+1] = prefix[i-first] + int64(a[i])
        }
 
        bestK := -1
        bestSum := int64(-1e18)
 
        // Ищем лучший ход
        for k := 1; k <= m && first+k <= n; k++ {
            if k == lastMove {
                continue
            }
            if prefix[k] > bestSum {
                bestSum = prefix[k]
                bestK = k
            }
        }
 
        // Если все варианты запрещены, берём k=1
        if bestK == -1 {
            bestK = 1
            bestSum = prefix[1]
        }
 
        // Применяем ход
        if pavelTurn {
            scorePavel += bestSum
        } else {
            scoreVika += bestSum
        }
 
        lastMove = bestK
        first += bestK
        pavelTurn = !pavelTurn
    }
 
    fmt.Println("\nРезультат:")
    if scorePavel > scoreVika {
        fmt.Println(1, "(Победил Павел)")
    } else {
        fmt.Println(0, "(Победила Вика)")
    }
}

package main

import (
	"fmt"
)

// Функция для нахождения НОД (алгоритм Евклида)
func gcd(x, y int64) int64 {
	for y != 0 {
		x, y = y, x%y
	}
	return x
}

// Функция для сокращения дроби
func reduceFraction(numerator, denominator *int64) {
	g := gcd(abs(*numerator), abs(*denominator))
	*numerator /= g
	*denominator /= g
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var a, b int
	fmt.Println("Сумма бесконечного ряда")

	fmt.Print("\nВведите a: ")
	fmt.Scan(&a)
	fmt.Print("Введите b: ")
	fmt.Scan(&b)

	if a < 1 || a > 10 || b < 1 || b > 10 {
		fmt.Println("Ошибка! a и b должны быть от 1 до 10")
		return
	}

	// Если b = 1, ряд расходится
	if b == 1 {
		fmt.Println("\nРезультат: infinity")
		return
	}

	var numerator int64 = 0
	var denominator int64 = 1

	// Вычисляем числитель и знаменатель по формулам
	switch a {
	case 1:
		numerator = int64(b)
		denominator = int64((b - 1) * (b - 1))
	case 2:
		numerator = int64(b * (b + 1))
		denominator = int64((b - 1) * (b - 1) * (b - 1))
	case 3:
		numerator = int64(b * (b*b + 4*b + 1))
		denominator = int64((b - 1) * (b - 1) * (b - 1) * (b - 1))
	case 4:
		numerator = int64(b * (b*b*b + 11*b*b + 11*b + 1))
		denominator = 1
		for i := 0; i < 5; i++ {
			denominator *= int64(b - 1)
		}
	case 5:
		numerator = int64(b * (b*b*b*b + 26*b*b*b + 66*b*b + 26*b + 1))
		denominator = 1
		for i := 0; i < 6; i++ {
			denominator *= int64(b - 1)
		}
	case 6:
		numerator = int64(b * (b*b*b*b*b + 57*b*b*b*b + 302*b*b*b + 302*b*b + 57*b + 1))
		denominator = 1
		for i := 0; i < 7; i++ {
			denominator *= int64(b - 1)
		}
	case 7:
		numerator = int64(b * (b*b*b*b*b*b + 120*b*b*b*b*b + 1191*b*b*b*b + 2416*b*b*b + 1191*b*b + 120*b + 1))
		denominator = 1
		for i := 0; i < 8; i++ {
			denominator *= int64(b - 1)
		}
	case 8:
		numerator = int64(b * (b*b*b*b*b*b*b + 247*b*b*b*b*b*b + 4293*b*b*b*b*b + 15619*b*b*b*b + 15619*b*b*b + 4293*b*b + 247*b + 1))
		denominator = 1
		for i := 0; i < 9; i++ {
			denominator *= int64(b - 1)
		}
	case 9:
		numerator = int64(b * (b*b*b*b*b*b*b*b + 502*b*b*b*b*b*b*b + 14608*b*b*b*b*b*b + 88234*b*b*b*b*b + 15619*b*b*b*b + 88234*b*b*b + 14608*b*b + 502*b + 1))
		denominator = 1
		for i := 0; i < 10; i++ {
			denominator *= int64(b - 1)
		}
	case 10:
		numerator = int64(b * (b*b*b*b*b*b*b*b*b + 1013*b*b*b*b*b*b*b*b + 47840*b*b*b*b*b*b*b + 455192*b*b*b*b*b*b + 1310354*b*b*b*b*b + 1310354*b*b*b*b + 455192*b*b*b + 47840*b*b + 1013*b + 1))
		denominator = 1
		for i := 0; i < 11; i++ {
			denominator *= int64(b - 1)
		}
	}

	// Сокращаем дробь
	reduceFraction(&numerator, &denominator)

	// Выводим результат в виде обыкновенной дроби
	fmt.Print("\nРезультат: ")
	if denominator == 1 {
		fmt.Printf("%d/1\n", numerator)
	} else {
		fmt.Printf("%d/%d\n", numerator, denominator)
	}
}

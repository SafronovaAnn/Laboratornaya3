use std::io;
 
fn main() {
    println!("Введите Xstart, Xend, dx:");
    
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Не удалось прочитать строку");
    let parts: Vec<f64> = input
        .split_whitespace()
        .map(|s| s.parse().expect("Пожалуйста, введите корректные числа"))
        .collect();
    
    if parts.len() != 3 {
        println!("Пожалуйста, введите три числа: Xstart Xend dx");
        return;
    }
    
    let (x_start, x_end, dx) = (parts[0], parts[1], parts[2]);
    
    println!("\n   x     |    y");
    println!("---------+---------");
    
    let mut x = x_start;
    while x <= x_end + 1e-9 {
        // Пропускаем точки разрыва
        if (x - (-2.0)).abs() < 1e-9 || (x - 2.0).abs() < 1e-9 {
            println!("{:8.4} |   разрыв", x);
        } else {
            let y = function(x);
            println!("{:8.4} | {:8.4}", x, y);
        }
        x += dx;
    }
}
 
fn function(x: f64) -> f64 {
    if x < -2.0 {
        // Левая часть: x < -2
        -0.5 * x - 1.5
    } else if x > 2.0 {
        // Правая часть: x > 2
        0.5 * x - 1.5
    } else {
        // Центральная часть: -2 < x < 2
        2.0 * (2.0 * x).cos()
    }
}
 

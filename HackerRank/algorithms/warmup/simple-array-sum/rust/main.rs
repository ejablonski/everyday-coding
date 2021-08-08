use std::io;

fn main() {
    let mut count = String::new();
    io::stdin().read_line(&mut count).ok().expect("Read error");

    let mut num = String::new();
    io::stdin().read_line(&mut num).ok().expect("Read error");
    let v: Vec<&str> = num.trim().split(' ').collect();
    
    let mut sum: i32 = 0;
    for num in &v {
        let num: i32 = num.parse().ok().expect("Parse error");
        sum += num;
    }

    println!("{}", sum);
}

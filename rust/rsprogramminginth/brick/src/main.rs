use std::io;

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn main() {
    let nm: Vec<i32> = input()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut mapping: Vec<String> = Vec::new();
    for _ in 0..nm[0] {
        mapping.push(input());
    }
}
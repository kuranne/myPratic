use std::{io};

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input;
}

fn main() {
    let n = input().trim().parse().unwrap();
    let mut temp: String;
    let mut mooks: HashSet<>
}
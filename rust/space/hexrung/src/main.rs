use std::io;

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn hextoria(n: i32, result: i32) {
    if n == 1 {return}
    else {return hextoria(n - 1, *&result);}
}

fn main() {
    let n: i32 = input().parse().unwrap();
    let result: i32 = 1;

    hextoria(n, *&result);

    println!("{}", result)
}
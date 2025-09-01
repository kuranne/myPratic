use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Error to read");

    let a: i32 = input.trim().parse().expect("Not as a Number");
    input.clear();
    io::stdin().read_line(&mut input).expect("Error to read");

    let b: i32 = input.trim().parse().expect("Not as a Number");
    let c: i32 = a + b;

    println!("{}", c);
}

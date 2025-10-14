use std::io;

fn input() -> String {
    let mut input: String = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input
}

fn multi(n: String) -> String {
    let mut res: String = String::new();
    for number in n {}
}

fn fac(n: i32) -> i32 {
    if n < 0 {
        return 0;
    } else if n == 0 {
        return 1;
    }

    let mut ans: i32 = 1;
    for i in 1..=n {
        ans *= i;
    }
    ans
}

fn main() {
    let n = input().trim().parse().unwrap();
    println!("{}", fac(n));
}

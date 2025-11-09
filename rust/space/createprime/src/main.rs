use std::io::{self};

fn is_prime(n: &i64, prime: &Vec<i64>) -> bool {
    let lmt: i64 = (*n as f64).sqrt() as i64;
    for val in prime {
        if *val > lmt {
            break;
        }
        if *n % *val == 0 {
            return false;
        }
    }
    true
}

fn primeat(n: usize) -> i64 {
    let mut prime: Vec<i64> = Vec::from([2]);
    let mut nextnum: i64 = 3;
    while prime.len() < n {
        if is_prime(&nextnum, &prime) {
            prime.push(*&nextnum);
        }
        nextnum += 2;
    }
    *prime.iter().last().unwrap()
}

fn main() -> io::Result<()> {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n = n.trim().parse::<usize>().unwrap();
    println!(
        "{}",
        if n > 1 {
            primeat(n)
        } else if n == 2 {
            2
        } else {
            0
        }
    );

    Ok(())
}

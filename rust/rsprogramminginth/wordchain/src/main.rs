use std::{io};

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn compare(a: &str, b:&str) -> bool {
    let mut check: usize = 0;

    for (i, j) in a.chars().zip(b.chars()) {
        if check == 3 {return false}
        if i != j {check+=1;} 
    }

    true
}

fn main(){
    let _length: usize = input().parse().unwrap();
    let number: usize = input().parse().unwrap();
    let mut chained: Vec<String> = vec![];
    if number > 1 {
        for _ in 0..number {
            let temp = input();
            chained.push(temp);
        }

        for i in 0..number {
            if i == 0 {continue;}
            if ! compare(&chained[i], &chained[i-1]) {
                println!("{}", chained[i-1]);
                break;
            }
            if i == number - 1 {println!("{}", chained[i]);}
        }
    }else {
        println!("{}", input());
    }

}
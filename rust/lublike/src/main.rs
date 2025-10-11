use std::{collections::HashMap, io};

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input;
}

fn main() {
    let _n: i32 = input().trim().parse().unwrap();

    let like: Vec<i32> = input()
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut score = HashMap::new();

    for i in like {
        if let Some(value) = score.get_mut(&i) {
            *value += 1;
        } else {
            score.insert(i, 1);
        }
    }

    let mut max_value = 0;
    for (_, value) in &score {
        if max_value < *value {max_value = *value}
    }

    let mut rst: Vec<i32> = score
        .iter()
        .filter(|&(_,&val)| val == max_value)
        .map(|(&key,_)| key)
        .collect();

    rst.sort();
    for k in rst {
        print!("{} ",k);
    }
    println!();
}

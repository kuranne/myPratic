use std::io;

fn main(){
    let mut rin = String::new();
    io::stdin().read_line(&mut rin).unwrap();

    let n: Vec<i32> = rin
        .split_whitespace()
        .map(|x|x.parse::<i32>().unwrap())
        .collect();

    println!("{:?}",n);
    // ค่อยมาต่อ, -> bed
}
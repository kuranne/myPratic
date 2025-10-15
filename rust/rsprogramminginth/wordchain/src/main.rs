use std::io;

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    input
}

fn main(){
    let length: usize = input().trim().parse().unwrap();
    let times: usize = input().trim().parse().unwrap();
    let mut ans: Vec<String> = vec![];

    for _ in 0..times {
        let temp = input().trim().to_string();
        if ans.len() == 0 {ans.push(temp); continue;}
        
        else {} // let study about iter first
        
        }
    }
}
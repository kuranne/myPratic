use std::io;

fn main(){
  let mut rin = String::new();
  io::stdin().read_line(&mut rin).expect("error");
  let a: i32 = rin.trim().parse().expect("input number!!!");
  rin.clear();
  io::stdin().read_line(&mut rin).expect("error");
  let b: i32 = rin.trim().parse().expect("number pls.");
  let c: i32 = a + b;
  println!("{:?}", c);
}
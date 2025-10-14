fn main() {
    let a: Vec<i32> = vec![];
    let ptra = &a;
    println!("{:p}\n{:p}", &a, &ptra);
}
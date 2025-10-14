use num_bigint::BigInt;

fn main() {
    let a: Vec<BigInt> = vec![];
    let ptra = &a;
    println!("{:p}\n{:p}", &a, &ptra);
}
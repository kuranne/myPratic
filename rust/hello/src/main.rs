use clap::{Parser};

#[derive(Parser, Debug)]
#[command(name = "hello", version, about = "print hello")]
struct Args {
    #[arg(short, long)]
    name: String,

    #[arg(short, long, default_value_t = 1)]
    time: u8
}

fn main() {
    let arg = Args::parse();
    if !arg.name.is_empty() {
        for _ in 0..arg.time {
            println!("hello, {}!", arg.name)
        }
    } else {
        for _ in 0..arg.time {
            println!("hello world!")
        }
    }
}
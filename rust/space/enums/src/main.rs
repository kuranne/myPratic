use std::io;

enum PlayerStatus {
    Alive{healt:i32},
    Stuns{healt:i32, time: i32},
    Dead
}

fn update_player (status: PlayerStatus) -> PlayerStatus {
    match status {
        PlayerStatus::Alive { healt } if healt <= 0 => PlayerStatus::Dead,
        PlayerStatus::Alive { healt } => PlayerStatus::Alive { healt },
        PlayerStatus::Stuns { healt, time } =>
            if time <= 1 {PlayerStatus::Alive { healt }}
            else {PlayerStatus::Stuns { healt , time: time - 1 }},
        PlayerStatus::Dead => PlayerStatus::Dead
    }
}

fn display_player (status: PlayerStatus) -> PlayerStatus{
    match status {
        PlayerStatus::Alive { healt } => println!("Alive with {} hp", healt),
        PlayerStatus::Stuns { healt, time } => println!("Stuning for {} turn(s), with {} hp", time, healt),
        PlayerStatus::Dead => println!{"Deaded"}
    }
    return status;
}

fn divide(a: i32, b: i32) -> Result<i32, String> {
    if b == 0 {
        Err("Can't divided by 0".to_string())
    } else {
        Ok(a / b)
    }
}

fn input() -> String {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input;
}

fn main(){
    let numbers:Vec<i32> = input().trim().split_whitespace().map(|x| x.parse().expect("input is not a number")).collect();
    let a: i32 = numbers[0];
    let b: i32 = numbers[1];
    println!("{:#?}", divide(a, b));

    let mut player = PlayerStatus::Alive { healt: a/b };
    display_player(player);
    player = PlayerStatus::Stuns {healt: a/b, time: 1};
    player = display_player(player);
    player = update_player(player);
    display_player(player);
    player = PlayerStatus::Alive { healt: 0};
    player = display_player(player);
    player = update_player(player);
    display_player(player);
}
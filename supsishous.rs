struct Sus {
    is_sus: bool,
    how_sus: u128,
}

fn main() {
    println!("so suspishous");
    
    let sussy = Sus {
        is_sus: true,
        how_sus: std::u128::MAX,
    };
    println!("Is sus: {}\nHow sus: {}", sussy.is_sus, sussy.how_sus);
}

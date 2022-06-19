struct Sus {
    is_sus: bool,
    how_sus: u128,
}

impl Default for Sus {
    fn default() -> Self {
        Self {
            is_sus: true,
            how_sus: std::u128::MAX,
        }
    }
}

fn main() {
    println!("so suspishous");
    
    let sussy = Sus::default();
    println!("Is sus: {}\nHow sus: {}", sussy.is_sus, sussy.how_sus);
}

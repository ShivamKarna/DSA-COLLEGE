// mod bubble_sort;
// mod selection_sort;
// mod insertion;
// mod radix;
// mod merge;

use rand::RngExt;
use std::time::Instant;
mod radix;

fn main() {
    // Initialize Array and size input
    let mut input = String::new();

    // Ask user to input array size
    println!("Enter size of array : ");

    if let Err(e) = std::io::stdin().read_line(&mut input) {
        print!("Something went wrong : {}", e);
    }

    let n: usize = input.trim().parse().expect("Error parsing !");

    let mut arr: Vec<i32> = (0..n)
        .map(|_| rand::rng().random_range(0..100_000))
        .collect();

    // Measure time
    let start = Instant::now();
    radix::sort(&mut arr);
    let duration = start.elapsed();

    println!("Time taken: {} seconds", duration.as_secs_f64());
}

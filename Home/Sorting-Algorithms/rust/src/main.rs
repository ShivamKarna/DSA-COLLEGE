// mod bubble_sort;
// mod selection_sort;
// mod insertion;
mod shell;
use rand::Rng;
use std::time::Instant;

// fn manual_swap(arr: &mut [i32], a: usize, b: usize) {
//     let temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

fn main() {
    // Initialize Array and size input
    let mut input = String::new();

    // Ask user to input array size
    println!("Enter size of array : ");
    match std::io::stdin().read_line(&mut input) {
        Ok(_) => println!(""),
        Err(e) => print!("Something went wrong : {}", e),
    }

    let n: usize = input.trim().parse().expect("Error parsing !");

    let mut arr: Vec<i32> = (0..n)
        .map(|_| rand::thread_rng().gen_range(0..100_000))
        .collect();

    // Measure time
    let start = Instant::now();
    shell::sort(&mut arr);
    let duration = start.elapsed();

    println!("Time taken: {} seconds", duration.as_secs_f64());
}

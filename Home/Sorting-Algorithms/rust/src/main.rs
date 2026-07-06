// mod bubble_sort;
// mod selection_sort;
mod insertion;
use rand::Rng;
use std::time::Instant;

// fn manual_swap(arr: &mut [i32], a: usize, b: usize) {
//     let temp = arr[a];
//     arr[a] = arr[b];
//     arr[b] = temp;
// }

fn main() {
    // Initialize Array and size input
    let mut arr = Vec::new();
    let mut input = String::new();

    // Ask user to input array size
    println!("Enter size of array : ");
    match std::io::stdin().read_line(&mut input) {
        Ok(_) => println!(""),
        Err(e) => print!("Something went wrong : {}", e),
    }

    let n: usize = input.trim().parse().expect("Error parsing !");

    arr.resize(n, 0);

    // Put random values in array
    for i in 0..n {
        arr[i] = rand::thread_rng().gen_range(1..=100_000);
    }

    // Measure time
    let start = Instant::now();
    insertion::sort(&mut arr);
    let duration = start.elapsed();

    println!("Time taken: {} seconds", duration.as_secs_f64());
}

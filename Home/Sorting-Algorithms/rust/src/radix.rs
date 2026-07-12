pub fn sort(arr: &mut [i32]) {
    let max_val = *arr.iter().max().unwrap_or(&0);
    if max_val == 0 {
        return;
    }
    let mut place: usize = 1;
    while max_val as usize / place > 0 {
        count_sort_by_digits(arr, place);
        place *= 10;
    }
}

fn count_sort_by_digits(arr: &mut [i32], place: usize) -> (){
    let n = arr.len();
    // array_of_count_of_digits : [0,0,0,0,0,0,0,0,0,0]
    let mut count = [0; 10];
    let mut output = vec![0;n];
    // count occurences of digits in the current place
    for &val in arr.iter() {
        let digit = (val as usize / place) % 10;
        count[digit as usize] += 1;
    }
    for i in 1..10 {
        count[i] = count[i] + count[i - 1];
    }
    for &val in arr.iter().rev(){
        let digit = (val as usize / place) % 10;
        output[count[digit] -1 ] = val;
        count[digit] -= 1;
    }
    arr.copy_from_slice(&output);
}

pub fn sort(arr: &mut [i32]) {
    let n = arr.len();
    if n < 2 {
        return;
    }
    for i in 1..n {
        let mut j = i;
        while j > 0 && arr[j] < arr[j - 1] {
            arr.swap(j - 1, j);
            j -= 1;
        }
    }
}

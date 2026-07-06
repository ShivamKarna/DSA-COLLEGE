pub fn sort(arr: &mut [i32]) {
    let n = arr.len();
    if n < 2 {
        return;
    }
    for i in 0..n - 1 {
        let mut min_index = i;
        for j in (i + 1)..n {
            if arr[j] < arr[min_index] {
                min_index = j;
            }
        }
        arr.swap(i, min_index);
    }
}

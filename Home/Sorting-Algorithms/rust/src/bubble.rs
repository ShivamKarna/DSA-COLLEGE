pub fn sort(arr: &mut [i32]) {
    let n = arr.len();
    if n < 2 {
        return;
    }
    for i in 0..n {
        for j in 0..n - i - 1 {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}

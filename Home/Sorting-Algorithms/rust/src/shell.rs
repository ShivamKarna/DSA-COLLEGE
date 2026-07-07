pub fn sort(arr: &mut [i32]) {
    let n: usize = arr.len();
    if n < 2 {
        return;
    }
    let mut gap: usize = n / 2;
    while gap > 0 {
        for i in gap..n {
            let temp = arr[i];
            let mut j = i;

            while j >= gap && arr[j - gap] > temp {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

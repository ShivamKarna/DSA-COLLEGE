fn partition(arr: &mut [i32]) -> usize {
    let pivot_index = arr.len() - 1;
    let mut i = 0;

    for j in 0..pivot_index {
        if arr[j] <= arr[pivot_index] {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, pivot_index);
    i
}

pub fn sort(arr: &mut [i32]) {
    if arr.len() <= 1 {
        return;
    }
    let pivot_index = partition(arr);
    sort(&mut arr[0..pivot_index]);
    sort(&mut arr[pivot_index + 1..]);
}

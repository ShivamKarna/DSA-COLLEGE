pub fn sort(arr: &mut [i32]) {
    let mid = arr.len() / 2;
    if mid == 0 {
        return;
    }
    // recursive sorting array
    sort(&mut arr[..mid]);
    sort(&mut arr[mid..]);

    let mut merged = Vec::<i32>::with_capacity(arr.len());
    let (left, right) = arr.split_at(mid);
    let (mut i, mut j) = (0, 0);

    while i < left.len() && j < right.len() {
        if left[i] < right[j] {
            merged.push(left[i]);
            i += 1;
        } else {
            merged.push(right[j]);
            j += 1;
        }
    }

    merged.extend_from_slice(&left[i..]);
    merged.extend_from_slice(&right[j..]);

    arr.copy_from_slice(&merged);
}

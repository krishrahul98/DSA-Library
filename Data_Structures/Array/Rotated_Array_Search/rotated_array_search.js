function rotatedBinarySearch(arr, k) {
    var l = 0,
        r = arr.length - 1;
    while (l <= r) {
        var m = Math.floor((l + r) / 2);

        if (arr[m] == k) {
            return m;
        }

        if (arr[l] < arr[m]) {
            if (arr[l] <= k && k < arr[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if (arr[m] <= k && k < arr[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
    }
    return -1;
}

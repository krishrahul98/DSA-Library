function heapify(array, length, i) {
    let max = i;
    let left = i * 2 + 1;
    let right = left + 1;

    if (left < length && array[left] > array[max]) {
        max = left;
    }

    if (right < length && array[right] > array[max]) {
        max = right;
    }

    if (max != i) {
        [array[i], array[max]] =[array[max], array[i]];

        heapify(array, length, max);
    }
    return array;
}

function heapSort(array) {
    let length = array.length;
    let i = Math.floor(length / 2 -1 );
    let k = length - 1;

    while ( i >= 0 ) {
        heapify(array, length, i);
        i--;
    }

    while ( k >= 0 ) {
        [array[0], array[k]] == [array[k], array[0]];
        heapify(array, k, 0);
        k--;
    }
    return array;
}
 function main(array) {
     console.log(`Input array is ${array}`);
     heapSort(array);
     console.log(`Sorted array is ${array}`)
 }
const array = [6, 5, 3, 1, 8, 7, 2, 4];

main(array);
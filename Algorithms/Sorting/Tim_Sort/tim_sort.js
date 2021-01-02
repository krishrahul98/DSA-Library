function insertionSort(array, startIdx, endIdx) {
    for (let i = startIdx; i < endIdx; i++) {
        let currentElement = array[i];
        let j = i - 1;
        while (j >= 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}

function mergeRuns(array, start, mid, end) {
    let firstArraySize = mid - start + 1;
    let secondArraySize = end - mid;
    let array1 = new Array(firstArraySize);
    let array2 = new Array(secondArraySize);
    let i = 0,
        j = 0,
        k = 0;

    for (i = 0; i < firstArraySize; i++) {
        array1[i] = array[start + i];
    }
    for (i = 0; i < secondArraySize; i++) {
        array2[i] = array[mid + 1 + i];
    }
    (i = 0), (j = 0), (k = start);

    while (i < firstArraySize && j < secondArraySize) {
        if (array1[i] <= array2[j]) {
            array[k] = array1[i];
            i++;
        } else {
            array[k] = array2[j];
            j++;
        }
        k++;
    }
    while (i < firstArraySize) {
        array[k] = array1[i];
        k++;
        i++;
    }

    while (j < secondArraySize) {
        array[k] = array2[j];
        k++;
        j++;
    }
}

function timSort(array, run = 32) {
    var arrayLength = array.length;

    console.log("Before sorting the array: ");
    console.log(...array);
    console.log("============");
    for (i = 0; i < array.length; i += run) {
        insertionSort(array, i, Math.min(i + run, arrayLength));
    }
    for (var split = run; split < arrayLength; split = 2 * split) {
        for (var startIdx = 0; startIdx < arrayLength; startIdx += 2 * split) {
            var endIdx = Math.min(startIdx + 2 * split - 1, arrayLength - 1);
            var mid = Math.min(
                startIdx + split - 1,
                Math.floor((startIdx + endIdx) / 2)
            );
            mergeRuns(array, startIdx, mid, endIdx);
        }
    }
    console.log("After sorting the array: ");
    console.log("============");
    console.log(...array);
}

var myArray = Array.from({ length: 150 }, () =>
    Math.floor(Math.random() * 10000)
);

timSort(myArray);

//binaryFindIndex is a function that performe a binary search and return an index where a given value(index of a value) should be inserted. 
function binaryFindIndex(array, index) {
    let lowerIndex = 0;
    let middleIndex = 0;
    let upperIndex = index - 1;
    let nextValue = array[index]
    let nextValueIndex;
    let indexFound = false
    index >= array.length ? (nextValueIndex = -1, indexFound = true) : null;
    while (upperIndex >= lowerIndex && !indexFound) {
        middleIndex = Math.floor((upperIndex + lowerIndex) / 2);
        if (upperIndex === lowerIndex || nextValue === array[middleIndex]) {
            nextValue > array[middleIndex] ? (nextValueIndex = middleIndex + 1, indexFound = true) : (nextValueIndex = middleIndex, indexFound = true)
        } else if (nextValue < array[middleIndex]) {
            upperIndex = middleIndex - 1;
        } else if (nextValue > array[middleIndex]) {
            lowerIndex = middleIndex + 1;
        }
    }

    return indexFound ? nextValueIndex : lowerIndex;
}

//insertAtIndex function takes an array, an index where the element should be inserted and elementIndex to get the element and also to delete the element at the old index.
function insertAtIndex(array, index, elementIndex) {
    array.splice(index, 0, array[elementIndex]);
    array.splice(elementIndex + 1, 1)
    return array;
}

//binaryInsertionSort function takes an array and sort it using binary search to find the next index. 
function binaryInsertionSort(array) {
    let arr = array.slice(0);
    for (let index = 1; index < arr.length; index++) {
        const insertionIndex = binaryFindIndex(arr, index, arr[index]);
        arr = insertAtIndex(arr, insertionIndex, index);
    }
    return arr;
}

const array = [24, 64, 20, 88, 33, 84, 47, 81, 12, 91]
const sortedArray = binaryInsertionSort(array)
console.log(sortedArray);
//Swap function swaps two positions in an arra and returns the new array.
function swap(array, firstIndex, secondIndex) {
    let exchParam = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = exchParam;

    return array;
}

function binarySort(array) {
    let firstIndex = 1;
    while (firstIndex < array.length) {
        let secondIndex = firstIndex;
        while (secondIndex > 0 && array[secondIndex - 1] > array[secondIndex]) {
            array = swap(array, secondIndex - 1, secondIndex)
            secondIndex--
        }
        firstIndex++
    }
    return array
}

const array = [6, 5, 3, 0, 0, 1, 8, 7, 5, 2, 4];
const sortedArray = binarySort(array)
console.log(sortedArray);
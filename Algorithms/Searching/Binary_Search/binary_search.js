// Javascript implementation of Binary Search 

const binarySearch = (array, element) => {
  let startIndex = 0;
  let endIndex = array.length - 1;

  while (startIndex <= endIndex) {

    let middleIndex = Math.floor((startIndex + endIndex) / 2);

    if (element === array[middleIndex]) {
      return middleIndex;
    }

    //Element is on the right side of the middle element
    if (element > array[middleIndex]) {
      startIndex = middleIndex + 1;
    }

    //Element is on the left side of the middle element
    else {
      endIndex = middleIndex - 1;
    }

  }

  return -1;
}

const getElementIndex = () => {

  var ar = [2, 3, 4, 10, 40];
  var el = 10;
  var ind = binarySearch(ar, el)

  if (ind === -1) {
    console.log("Element not present");
  } else {
    console.log("Element found at " + ind + " index");
  }

}

getElementIndex();

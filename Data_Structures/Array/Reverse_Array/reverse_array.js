// REVERSING AN ARRAY

/*
 * Write two functions, reverseArray and reverseArrayInPlace.
 * The first, reverseArray, takes an array as argument and produces a new array that has the same elements in the inverse order.
 * The second, reverseArrayInPlace, does what the reverse method does: it modifies the array given as argument by reversing its elements. Neither may use the standard reverse method.
 */

//reverseArray() using unshift
function reverseArray(array) {
  let newArray = [];
  for (let i = 0; i < array.length; i++) {
    newArray.unshift(array[i]);
  }
  return newArray;
}

//reverseArray() using push and reverse iteration
function reverseArray2(array) {
  let newArray = [];
  for (let i = array.length - 1; i >= 0; i--) {
    newArray.push(array[i]);
  }
  return newArray;
}

//reverseArrayInPlace()
function reverseArrayInPlace(array) {
  for (let i = 0; i < Math.floor(array.length / 2); i++) {
    let temp = array.length - 1 - i;
    let hold = array[i];
    array[i] = array[temp];
    array[temp] = hold;
  }
}

//Print to console

console.log("reverseArray() result is...");
console.log(reverseArray(["A", "B", "C"]));
// → ["C", "B", "A"];

console.log("\n");

console.log("reverseArray2() result is...");
console.log(reverseArray2(["D", "E", "F"]));
// → ["F", "E", "D"];

console.log("\n");

let arrayValue = [1, 2, 3, 4, 5];
console.log("reverseArrayInPlace() result is...");
reverseArrayInPlace(arrayValue);
console.log(arrayValue);
// → [5, 4, 3, 2, 1]

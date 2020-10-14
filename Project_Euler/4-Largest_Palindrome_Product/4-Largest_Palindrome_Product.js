"use strict";

const MAX3 = 999;
const MIN3 = 100;
const MAXDIGITS = 6;

function is_palindromic(digits) {
  let len = digits.length;

  for (
    let i = 0;
    i < len;
    i++ /* only really need to test half of the string - if even and int(half)+1 if odd  - but more complexity */
  )
    if (digits[i] != digits[len - (i + 1)]) return false;

  return true;
}

let maxp = 0;
let mini = MIN3;
let minj = MIN3;
let maxj = MAX3;

for (let i = MAX3; i >= mini; i--) {
  for (let j = maxj; j >= minj; j--) {
    let product = i * j;
    let digits = product.toString().split("", 6);
    if (is_palindromic(digits))
      if (product > maxp) {
        maxp = product;
        mini = minj = product / 1000; // optimize
      }
  }
  maxj = i;
}

console.log(maxp);

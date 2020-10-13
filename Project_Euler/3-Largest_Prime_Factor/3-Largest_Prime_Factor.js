"use strict";

let number = 600851475143;
let max_prime = 0;
let i = 3;

while (number != 1) {
  if (number % i) i += 2;
  else {
    max_prime = i;
    number = number / i;
  }
}

console.log(max_prime);

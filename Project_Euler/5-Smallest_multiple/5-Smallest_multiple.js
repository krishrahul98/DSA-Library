"use strict";

const MAX = 20;

function isprime(num) {
  if (num % 2) {
    if (num < 8) {
      return !(num === 1);
    } else {
      let divisor = 3;
      while (divisor * divisor <= num) {
        if (!(num % divisor)) return 0;
        divisor += 2;
      }
      return 1;
    }
  } else {
    return num === 2;
  }
}

let i = 2;
let try_product = 1;
let total = 1;

while (i <= MAX) {
  if (isprime(i)) {
    if (try_product) {
      if (i * i > MAX) {
        try_product = 0;
      } else {
        let tmp = i;
        let last = tmp;
        while (tmp <= MAX) {
          last = tmp;
          tmp *= i;
        }
        total *= last;
      }
    }
    if (!try_product) total *= i;
  }
  i++;
}

console.log(total);

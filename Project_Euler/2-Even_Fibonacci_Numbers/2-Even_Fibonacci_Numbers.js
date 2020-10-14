"use strict";

const max = 4000000;

let total = 0;
let previous = 1;
let current = 1;

while (current < max) {
  let next = current + previous;
  if (!(current % 2)) total += current;
  previous = current;
  current = next;
}

console.log(total);

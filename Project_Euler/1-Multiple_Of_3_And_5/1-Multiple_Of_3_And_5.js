"use strict";

const max = 1000;

let total = 0;

for (let i = 0; i < max; i++) if (!(i % 3) || !(i % 5)) total += i;

console.log(total);

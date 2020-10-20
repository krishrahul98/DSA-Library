const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function getNumber(prompt) {
  return new Promise((res) => {
    rl.question(prompt, (answer) => {
      answer = parseInt(answer);
      if (isNaN(answer))
        res(null);

      else res(answer);
    });
  });
}

async function main() {
  let numList = [];

  // Get data from user
  console.log('Enter a series of numbers to an array (Press enter twice when finished).');

  let recv;
  do {
    recv = await getNumber(`[${numList.length}]>>> `);
    if (recv !== null) numList.push(recv);
  } while (recv !== null);

  // Sort number list in ascending order
  console.log(`Received ${numList.length} numbers. Sorting...`);
  console.log('Sorted! List of elements:\n' + numList.sort((n, m) => n - m).toString());

  // Get variables required for searching
  let jump = Math.floor(Math.sqrt(numList.length)); // The amount of elements to jump
  let searchFor = await getNumber('Enter a number to search for (First index is returned): '); // The number to search for
  console.log(`Searching for ${searchFor}...`);
  let index = 0;

  // Jump until element is found with a lower value
  for (let i = 0; numList[i] < searchFor; i += jump)
    index = i;

  // From the found index position, iterate to the next jump period searching
  // for the wanted number.
  for (let i = index; i <= index + jump; ++i)
    if (numList[i] === searchFor) {
      console.log(`Found first element of ${searchFor} at index ${i}`);
      process.exit(0);
    }

  // If no elements were found, it does not exist.
  console.log(`The number ${searchFor} is not in the list.`);
  process.exit(0);
}

main();

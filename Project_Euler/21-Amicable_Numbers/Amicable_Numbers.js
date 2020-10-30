
// Number choosen by the problem.
const value = 10000;
// Each element in the array will be the sum of the divisors of the element.
var sum_of_divisors = new Array();

//This function will calculate the sum of the divisors of the dividend passed as parameter.
function sum_divisors(dividend) {
  let result = 1;
  let limit = (1 + Math.round(Math.sqrt(dividend)));
  for(var i = 2; i < limit; i++){
    if(dividend % i === 0){
      result += i;
      if(dividend !== i*i){
        result += (dividend/i);
      }
    }
  }
  return result;
}

// This is to use the function when the screen loads.
window.onload = calculate();

// This function is to calculate the sum of amicable numbers less than 10000.
function calculate(){

  // This variable is used to keep track of the sum of amicable numbers in the second loop.
  let answer = 0;

  // This loop fill the sum_of_divisors array.
  for(let i = 2; i < value; i++){
    sum_of_divisors[i] = sum_divisors(i);
  }


  // This loops add the amicable numbers to answer
  for(let i = 2; i < value; i++){

    // This is to simplify the checking in the if statement.
    let n = sum_of_divisors[i];

    // You can use this checking 'sum_of_divisors[sum_of_divisors[i]] === i' in the if statement below
    // I added the 'let n' to help simplify the statement.
    if(sum_of_divisors[i] < value && sum_of_divisors[n] === i && sum_of_divisors[i] !== i){  
      answer += i;
    }
  }

  //This is to print the answer on the console.
  console.log(answer);
};
  

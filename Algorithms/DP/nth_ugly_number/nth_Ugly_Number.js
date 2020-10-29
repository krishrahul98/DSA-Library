const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

function min(a, b) {
	if (a > b) {
		return b
	}
	return a
}

readline.question('Enter the n!\n', n => {
  dp = [1]
  var index2 = 0, index3 = 0, index5 = 0
  var next2 = 2, next3 = 3, next5 = 5
  for(var i = 1; i < n; i++) {
  	var min_val = min(next2, min(next3, next5))
  	dp.push(min_val)
  	if (dp[i] == next2) {
  		index2 += 1
  		next2 = 2 * dp[index2]
  	}
  	if (dp[i] == next3) {
  		index3 += 1
  		next3 = 3 * dp[index3]
  	}
  	if (dp[i] == next5) {
  		index5 += 1
  		next5 = 5 * dp[index5]
  	}
  }
  console.log(n + 'th ugly number is:', dp[n-1])
  readline.close();
});
package main

import (
	"fmt"
	"strconv"
)
func min(a, b int) int {
	if a > b {
		return b
	} 
	return a
}


func get_nth_ugly_number(n int) int {
	dp := []int{1}
	var index2, index3, index5 = 0, 0, 0
	var next2, next3, next5 = 2, 3, 5
	for i := 1; i < n; i++ {
		min_val := min(next2, min(next3, next5))
		dp = append(dp, min_val)
		if dp[i] == next2 {
			index2 += 1
			next2 = 2 * dp[index2]
		}
		if dp[i] == next3 {
			index3 += 1
			next3 = 3 * dp[index3]
		}
		if dp[i] == next5 {
			index5 += 1
			next5 = 5 * dp[index5]
		}
	}
	return dp[n-1]
}

func main() {
	var n string
	fmt.Println("Enter the n!")
	fmt.Scan(&n)
	var nth_ugly_num int
	nth, _ := strconv.Atoi(n)
	nth_ugly_num = get_nth_ugly_number(nth)
	fmt.Println(n + "th ugly number is:", nth_ugly_num)
}
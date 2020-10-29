def get_nth_ugly_number(n):
	dp = [0] * n
	dp[0] = 1
	index2, index3, index5 = 0, 0, 0
	next2, next3, next5 = 2, 3, 5

	for i in range(1, n):
		dp[i] = min(next2, next3, next5)
		if dp[i] == next2:
			index2 += 1
			next2 = 2 * dp[index2]
		if dp[i] == next3:
			index3 += 1
			next3 = 3 * dp[index3]
		if dp[i] == next5:
			index5 += 1
			next5 = 5 * dp[index5]
	return dp[-1]


def main():
	n = int(input('Enter the n!\n'))
	ans = get_nth_ugly_number(n)
	print(str(n) + 'th ugly number is:', ans)


if __name__ == '__main__':
	main()
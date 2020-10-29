def get_length_of_lcs(x, y):
	X, Y = len(x), len(y) # m, n
	dp = [[None] *(Y+1) for i in range(X+1)]
	for i in range(X+1):
		for j in range(Y+1):
			if i == 0 or j == 0:
				dp[i][j] = 0
			elif x[i-1] == y[j-1]:
				dp[i][j] = dp[i-1][j-1] + 1
			else:
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
	return dp[X][Y]


def main():
	x = input('Enter the first string!\n')
	y = input('Enter the second string\n')

	lcs = get_length_of_lcs(x, y)
	print('Length of longest common subsequence of', x, 'and', y, 'is', lcs,'\n')


if __name__ == '__main__':
	main()
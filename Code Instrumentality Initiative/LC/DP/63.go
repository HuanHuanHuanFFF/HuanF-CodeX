package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	n, m := len(obstacleGrid), len(obstacleGrid[0])
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, m)
	}
	for i := 0; i < m; i++ {
		if obstacleGrid[0][i] != 1 {
			dp[0][i] = 1
		} else {
			break
		}
	}
	for i := 0; i < n; i++ {
		if obstacleGrid[i][0] != 1 {
			dp[i][0] = 1
		} else {
			break
		}
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if obstacleGrid[i][j] != 1 {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	return dp[n-1][m-1]
}

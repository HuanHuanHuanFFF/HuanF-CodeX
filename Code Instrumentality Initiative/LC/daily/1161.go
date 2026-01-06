package main

type TreeNode struct {
	Val         int
	Left, Right *TreeNode
}

func maxLevelSum(root *TreeNode) int {
	sum := make(map[int]int, 1e5)
	var dfs = func(x *TreeNode, dep int) {}
	dfs = func(x *TreeNode, dep int) {
		if x == nil {
			return
		}
		if _, exist := sum[dep]; exist {
			sum[dep] += x.Val
		} else {
			sum[dep] = x.Val
		}
		dfs(x.Left, dep+1)
		dfs(x.Right, dep+1)
	}
	dfs(root, 1)
	ans, mx := int(1e9), int(-2e9)
	for x, y := range sum {
		if y >= mx {
			if y == mx {
				ans = min(ans, x)
			} else {
				ans = x
			}
			mx = y
		}
	}
	return ans
}

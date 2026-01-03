package main

// TreeNode Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	var dfs func(now *TreeNode) int
	ans := int(-1e9)
	dfs = func(now *TreeNode) int {
		lv, rv := 0, 0
		if now.Left != nil {
			lv = max(0, dfs(now.Left))
		}
		if now.Right != nil {
			rv = max(0, dfs(now.Right))
		}
		ans = max(lv+rv+now.Val, ans)
		return max(lv, rv) + now.Val
	}
	dfs(root)
	return ans
}

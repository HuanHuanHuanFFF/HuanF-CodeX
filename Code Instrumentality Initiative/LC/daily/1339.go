package main

func maxProduct(root *TreeNode) int {
	const MOD = int64(1e9 + 7)
	var sum, ans int64 = 0, 0
	var dfs1 func(x *TreeNode) int
	dfs1 = func(x *TreeNode) int {
		if x == nil {
			return 0
		}
		sum = sum + int64(x.Val)
		x.Val += dfs1(x.Left) + dfs1(x.Right)
		return x.Val
	}
	dfs1(root)
	var dfs2 func(x *TreeNode)
	dfs2 = func(x *TreeNode) {
		if x == nil {
			return
		}
		ans = max(ans, (sum-int64(x.Val))*int64(x.Val))
		dfs2(x.Left)
		dfs2(x.Right)
	}
	dfs2(root)
	return int(ans % MOD)
}

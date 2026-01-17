package main

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	var dfs func(root *TreeNode) (int, *TreeNode)
	dfs = func(root *TreeNode) (int, *TreeNode) {
		if root == nil {
			return 0, nil
		}
		d1, lca1 := dfs(root.Left)
		d2, lca2 := dfs(root.Right)
		if d1 > d2 {
			return d1 + 1, lca1
		}
		if d1 < d2 {
			return d2 + 1, lca2
		}
		return d1 + 1, root
	}
	_, ans := dfs(root)
	return ans
}

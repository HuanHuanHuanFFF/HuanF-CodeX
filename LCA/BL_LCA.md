# 倍增（Binary Lifting）求树上最低公共祖先（LCA）

## 1. 算法概述

- **目标**：在有根树中，给定任意两结点 `u, v`，快速地求出它们的最低公共祖先（Lowest Common Ancestor，LCA）。  
- **思路**：利用“二进制分解 + 预处理”思路，预先计算出每个结点往上跳 `2^k` 步后所到达的祖先节点，并在查询时按二进制位将深度差对齐，最后同步跳跃定位 LCA。

## 2. 关键数据结构

```text
n         — 树的节点总数  
LOG       — ⌊log₂(n)⌋ 的上界，满足 2^LOG ≥ n  
adj[]     — 邻接表，存储树的边  
depth[]   — depth[v]：节点 v 到根的深度（根深度为 0）  
up[v][k]  — up[v][k]：节点 v 向上跳 2^k 步后的祖先。  
             k=0 时即直接父节点；k>0 时由小 k 递推得到
```

## 3. 预处理（Building the “up” 表）

1. **DFS 初始化**  
   - 从根节点（如 1）出发，DFS 遍历：  
     ```java
     void dfs(int v, int p) {
         up[v][0] = p;
         for (int to : adj[v]) {
             if (to == p) continue;
             depth[to] = depth[v] + 1;
             dfs(to, v);
         }
     }
     ```
   - 结果：`up[v][0]` 填为父节点，`depth[v]` 填为深度。

2. **倍增 DP**  
   ```java
   for (int k = 1; k <= LOG; k++) {
       for (int v = 1; v <= n; v++) {
           up[v][k] = up[ up[v][k - 1] ][k - 1];
       }
   }
   ```
   - 利用递推关系：  
     > up[v][k] = 从 v 跳 2^k 步后的祖先 = up( up[v][k−1], k−1 )  
   - 时间复杂度：`O(n · log n)`

## 4. 查询 LCA

```java
int lca(int u, int v) {
    // 1. 保证 u 深度 ≥ v
    if (depth[u] < depth[v]) {
        int t = u; u = v; v = t;
    }
    // 2. 深度对齐
    int diff = depth[u] - depth[v];
    for (int k = 0; k <= LOG; k++) {
        if ((diff >> k & 1) == 1) {
            u = up[u][k];
        }
    }
    if (u == v) return u;
    // 3. 同步跳跃
    for (int k = LOG; k >= 0; k--) {
        if (up[u][k] != up[v][k]) {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];  // 返回它们的父节点
}
```

### 查询步骤

1. **深度对齐**：将 `u` 跳上来，使 `depth[u] == depth[v]`。  
2. **同步跳跃**：从最高位往下，若 `up[u][k] != up[v][k]`，则同时跳 `2^k` 步。  
3. **返回结果**：最后一跳后，`up[u][0]` 即为 LCA。

## 5. 复杂度分析

- 预处理：`O(n · log n)`  
- 每次查询：`O(log n)`

## 6. 小结

- **核心思想**：二进制分解深度差 + 倍增表快速跳跃  
- **优点**：支持海量查询，常见于树型问题的基础模块  
- **注意**：根节点父亲可设为自己或 0，避免越界

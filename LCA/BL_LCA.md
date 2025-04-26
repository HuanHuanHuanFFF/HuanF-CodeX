# 倍增法求 LCA — 中文极简笔记

| 符号        | 含义                     |
|-------------|--------------------------|
| `depth[v]`  | 结点 `v` 的深度           |
| `up[v][k]`  | `v` 向上 `2^k` 层祖先     |
| `LOG`       | 最小整数, 满足 `2^LOG ≥ n` |

---

## 核心思想

1. **二进制分解深度差**  
   - 任何整数步数可写成若干个 `2^k` 之和。  
   - 用此思想一次性把深度大的结点“跳高”到同一深度。

2. **同步倍增跳跃**  
   - 预先存好每个结点的 `2^k` 祖先。  
   - 自高位向低位比较，若两结点在某层祖先不同，则同时上跳 `2^k` 层。  
   - 跳完后，它们父亲即为 LCA。

这样把**树上路径查询**转化为**二进制跳跃**，查询时间从 `O(高度)` 降到 `O(log n)`。

---

## 预处理 `O(n log n)`

```cpp
void dfs(int v,int p){
    up[v][0]=p;
    for(int to:adj[v]) if(to!=p){
        depth[to]=depth[v]+1;
        dfs(to,v);
    }
}
for(int k=1;k<=LOG;k++)
    for(int v=1;v<=n;v++)
        up[v][k]=up[ up[v][k-1] ][k-1];
```

---

## 查询 `O(log n)`

```cpp
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int d=depth[u]-depth[v];
    for(int k=0;k<=LOG;k++) if(d>>k&1) u=up[u][k];
    if(u==v) return u;
    for(int k=LOG;k>=0;k--)
        if(up[u][k]!=up[v][k]){
            u=up[u][k];
            v=up[v][k];
        }
    return up[u][0];
}
```

---

## 使用流程

1. 建图  
2. `dfs` + 倍增预处理  
3. 多次调用 `lca(u,v)` 回答查询  

> **备注**：只存必须信息，逻辑分三独立模块：①状态定义 ②建表 ③查询。
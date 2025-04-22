# 二维树状数组（2D BIT）简洁总结

## What - 是什么？

**二维树状数组（2D Binary Indexed Tree）** 是 **树状数组** 的拓展，用于支持对二维矩阵进行 **区间查询** 和 **单点/区域更新**，时间复杂度为 \( O(\log n \log m) \)。

## Why - 为什么使用？

- **高效支持矩阵区域更新/求和**：解决普通二维数组效率低的问题。
- **简洁实现**：延续 BIT 的 lowbit 思想，只是嵌套使用两层。
- **适用于**：
  - 子矩阵求和
  - 矩形加法/查询
  - 动态二维统计（如图像处理、区块更新）

## How - 如何实现？

### 一、定义 lowbit 操作：

```cpp
int lowbit(int x) {
    return x & -x;
}
```

### 二、核心结构：

定义一个二维数组 `tree[x][y]` 来维护前缀信息。

### 三、单点更新操作（加 val 到 (x, y)）：

```cpp
void add(int x, int y, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            tree[i][j] += val;
}
```

### 四、前缀和查询（从 (1,1) 到 (x,y)）：

```cpp
int query(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            res += tree[i][j];
    return res;
}
```

### 五、矩形查询：

查询 \((x_1, y_1)\) 到 \((x_2, y_2)\) 的矩阵和：

```cpp
int sum(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) 
                         - query(x2, y1 - 1) 
                         + query(x1 - 1, y1 - 1);
}
```

## Extension - 多用途拓展（4 BIT 技巧）

为了支持 **二维矩阵的区间加 + 区域查询**，可以维护 **4 棵树状数组**（例如 `d1`, `d2`, `d3`, `d4`），通过差分和组合技巧实现更复杂的功能（参考 P4514）。
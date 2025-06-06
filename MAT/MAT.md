# 矩阵在算法竞赛中的极简笔记

> **原则**：只保留解决问题所需的最小信息，模块之间低耦合。

---

## 1 什么是矩阵 (What)

- **定义**：`r × c` 的二维数字表。  
- **存储**：直接用二维数组 / `vector<vector<long long>>`.

---

## 2 为什么用矩阵 (Why)

| 场景       | 作用示例                         |
|-----------|----------------------------------|
| 网格模型   | 迷宫最短路、图像旋转             |
| 图表示     | 邻接矩阵 → Floyd、多源最短路      |
| 动态规划   | `dp[i][j]` 状态表                |
| 线性方程组 | 高斯消元                         |
| 递推加速   | **矩阵快速幂** 求第 n 项          |

---

## 3 如何用矩阵 (How)

### 3.1 基本操作

| 操作   | 复杂度      | 备注           |
|--------|-------------|----------------|
| 加/减  | `O(rc)`     | 元素级运算     |
| 乘法   | `O(rck)`<br>(常见 `n³`) | 竞赛多用朴素乘 |
| 转置   | `O(rc)`     | 行列互换       |
| 旋转90°| 转置后反转行/列          |

### 3.2 常见算法模块

- **高斯消元**：解 `Ax=b`，`O(n³)`  
- **矩阵链乘 DP**：最小乘法次数，`O(n³)`  
- **网格 BFS/DFS**：把坐标当作节点遍历  
- **邻接矩阵 k 步路径数**：`A^k`

---

## 4 核心模块：矩阵快速幂

### 4.1 思想

- 线性递推 `f(n)=a·f(n−1)+b·f(n−2)…`  
- 写成 **转移矩阵** `M`：`state(n)=M·state(n-1)`  
- 目标为求 `M^k`，用 **快速幂** 将时复杂度降至 `O(log n)`.

### 4.2 斐波那契模板

> 递推 `F(n)=F(n−1)+F(n−2)`

$$
M = \begin{pmatrix}
1 & 1 \\
1 & 0
\end{pmatrix},
\qquad
\begin{pmatrix}
F(n) \\
F(n-1)
\end{pmatrix}
= M^{\,n-1}
\begin{pmatrix}
F(1) \\
F(0)
\end{pmatrix}.
$$



```cpp
struct Mat{
    long long a[2][2];
    Mat(){ a[0][0]=a[1][1]=1; a[0][1]=a[1][0]=0; }  // 单位矩阵
};
Mat mul(Mat x,Mat y){
    Mat r{};
    r.a[0][0]=x.a[0][0]*y.a[0][0]+x.a[0][1]*y.a[1][0];
    r.a[0][1]=x.a[0][0]*y.a[0][1]+x.a[0][1]*y.a[1][1];
    r.a[1][0]=x.a[1][0]*y.a[0][0]+x.a[1][1]*y.a[1][0];
    r.a[1][1]=x.a[1][0]*y.a[0][1]+x.a[1][1]*y.a[1][1];
    return r;
}
Mat power(Mat b,long long n){
    Mat res;
    for(;n;n>>=1){
        if(n&1) res=mul(res,b);
        b=mul(b,b);
    }
    return res;
}
long long fib(long long n){
    if(n<=1) return n;
    Mat M{{1,1},{1,0}};
    Mat R=power(M,n-1);
    return R.a[0][0];               // F(n)
}
```

### 4.3 应用

| 问题               | 做法                           |
|--------------------|--------------------------------|
| 线性递推第 n 项    | 建 `k × k` 转移矩阵，求 `M^{n−k}` |
| 图 k 步路径条数    | 邻接矩阵 `A`，答案 `A^k[u][v]` |
| 自动机 DP          | 状态转移矩阵 + 快速幂          |

---

## 5 结论

- **矩阵 = 通用建模 + 统一运算**  
- **快速幂 = 把“迭代”换成“指数”** → `O(log n)`  
- 记住三步：**定义 → 操作 → 快速幂模板**，即可覆盖大多数竞赛题。

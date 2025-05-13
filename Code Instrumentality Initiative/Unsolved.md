### A. 贪吃蛇

**link**：https://codeforces.com/gym/105423  
**标签**：几何建模、向量运算、DAG 最长路径、拓扑排序  
**简单思路**：

1. 枚举两点差向量作为蛇头初始方向；
2. 用点积 ≥ 0 保证夹角 ≤ 90°，再结合叉积符号约束旋转方向，判断从当前点能否转向下一个点；
3. 将所有合法转向构造成有向无环图（DAG），对 DAG 做入度拓扑 BFS，维护 `dis[v]=max(dis[v],dis[u]+1)`，最终得最长路径长度。

### J. Beautiful Sequence

**link**：https://codeforces.com/gym/105423  
**标签**：哈希、线段树、双指针、子序列

**简单思路**：

1. 预处理两个排列中每个值在序列 1 和序列 2 中的下标映射 `pos1[i]`、`pos2[i]`
2. 使用双指针枚举区间右端 `r`，在区间 `[l…r]` 上通过线段树（或 BIT）维护子序列的相对顺序哈希
3. 对每个 `r`，移动左指针 `l` 直到区间在两序列中哈希相等，保持美丽序列性质
4. 每次固定 `r` 时，合法的美丽序列个数为 `r - l + 1`，累加到答案
5. 时间复杂度 O(n log n)，空间复杂度 O(n)

### H. 经文

**link**：https://codeforces.com/gym/105423  
**标签**：字符串、KMP、DP

**简单思路**：

1. 预处理模式串 s 的 KMP next 数组 `next[i][c]`，表示已匹配前缀长度 i 遇到字符 c 后转移到的新匹配长度
2. 定义三维 DP：`dp[i][j][t]` 表示已构造长度 i，恰好包含 j 个不重叠的 s，且当前已匹配前缀长度为 t 的方案数
3. 转移时枚举下一个字符 c∈‘a’…‘z’，计算 `nt=next[t][c]`
    - 若 `nt==|s|`，说明又匹配完一次 s，匹配数要 +1，新的匹配长度置为 `next[nt][c]`（或 0）
    - 否则新的匹配长度为 `nt`
    - `dp[i+1][j+(nt==|s|)][t′] += dp[i][j][t]`
4. 答案为 `sum(dp[n][k][t]) (0≤t<|s|) mod 998244353`

时间复杂度 O(26·n·k)，空间可用滚动数组优化到 O(k·|s|)

### E. Forbidden Prefix

**link**：https://atcoder.jp/contests/abc403/tasks/abc403_e  
**标签**：字符串、Trie、动态维护、前缀

**简单思路**：

1. 用 Trie 存储所有已插入到 X 的字符串，节点维护：
    - `next[26]`：子节点指针
    - `f`：标记该节点是否为某个 X 字符串的终点
    - `Zv`：存放经过该节点且尚未被判 bad 的 Y 字符串 ID 列表
2. 插入 X (T=1)：
    - 遍历 S 到达节点 u，设置 `f[u]=true`
    - 遍历 `Zv[u]`，将对应 Y ID 标记为 bad 并 `badY++`，清空 `Zv[u]`
3. 插入 Y (T=2)：
    - 分配新 ID，沿 S 的路径遍历每个节点 u：
        - 若 `f[u] == true`，立即标记该 Y 为 bad 并 `badY++`，停止遍历
        - 否则将 Y ID 推入 `Zv[u]`
    - `totalY++`
4. 每次输出 `totalY - badY` 即当前合法的 Y 字符串数
5. 时间复杂度 O(∑|S|)，空间复杂度 O(∑|S|)

# H. 土卫十六

**link**：[https://codeforces.com/contest/2094/problem/H](https://codeforces.com/contest/2094/problem/H)
**标签**：数论、因子枚举、二分查找、数据结构

**简单思路**：

1. 预处理：用 `vector<vector<int>> pos` 记录每个值在原数组中出现的下标（升序）。
2. 对于每次查询 `(k, l, r)`，枚举 `k` 的所有因子 `d`（可预先计算或 √(k) 现场枚举）。
3. 对每个因子 `d`，在 `pos[d]` 上用 `lower_bound` 找到第一个 ≥ `l` 的下标 `idx`，若 `idx ≤ r`，则视为事件 `(idx, d)`。
4. 将所有事件按 `idx` 升序排序，维护 `cur = k`、`prev = l` 和答案 `ans = 0`：

    * 对每个事件 `(idx, d)`：先累加 `(idx - prev) * cur`，再在 `idx` 处将 `cur` 中所有 `d` 因子除尽，更新 `prev = idx`。
5. 最后累加剩余区间 `[prev, r]` 的贡献 `(r - prev + 1) * cur`，输出 `ans`。

### E. 水果排列

**link
**：[https://atcoder.jp/contests/abc405/tasks/abc405\_e?lang=en](https://atcoder.jp/contests/abc405/tasks/abc405_e?lang=en)

**标签**：组合数学、偏序计数、分界枚举、组合数

**简单思路**：

1. 设 $N = A + B + C + D$，水果总数。
2. 枚举“最右苹果”所在位置 $i$，合法范围：$A \le i \le A + B$。
3. 左侧前 $i-1$ 个位置放置其余 $A-1$ 个苹果和 $B$ 个橘子，方案数：

   $$
   \binom{i-1}{A-1}
   $$
4. 右侧后 $N - i$ 个位置放置 $C$ 个香蕉和 $D$ 个葡萄，方案数：

   $$
   \binom{N - i}{C}
   $$
5. 对所有 $i$ 累加左右方案数乘积，取模 $998244353$：

   $$
   \sum_{i=A}^{A+B} \binom{i-1}{A-1} \times \binom{N - i}{C} \bmod 998244353
   $$

* 时间复杂度：$O(N)$ 预处理 + $O(B)$ 枚举
* 空间复杂度：$O(N)$


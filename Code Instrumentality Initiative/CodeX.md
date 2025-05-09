# D. 音乐预测

link: https://codeforces.com/contest/2042/problem/D

**标签**：扫描线、区间覆盖、离线处理、平衡树、有序集合、对称化

**本质思路**  
通过离线处理（按左端排序）和有序集合（`std::set.lower_bound`）将时间复杂度从 \(O(n^2)\) 降到 \(O(n\log n)\)。

**关键步骤**

1. **离线排序**  
   将所有区间按 \((l\ ↑,\ r\ ↓)\) 排序，保证遍历到 \([l_i,r_i]\) 时，所有满足 \(l_j\le l_i\) 的候选 predictors 已加入数据结构。
2. **在线查询**  
   用 `set<int>` 存放已处理区间的右端点，在遍历时用 `lower_bound(r_i)` 找到最小的 \(r_j\ge r_i\)，即 predictors 交集的右端，累加
   \(\max(0,\,r_j - r_i)\)。
3. **对称化处理**  
   将区间映射为 \([-r,-l]\) 后复用同样流程，得到左端推荐长度 \(\max(0,\,l_i - L)\)。
4. **去重**  
   相同原始区间的用户答案置 0。

整体复杂度：两次 \(O(n\log n)\) 扫描，合计 \(O(n\log n)\)。

# K. 渡劫

link: https://codeforces.com/gym/105423

**标签**：状态扩展、分层图、Dijkstra、最短路、超级源

**本质思路**  
将“一次免费通道”作为状态扩展成两层节点（未用/已用），再连同“直接完成渡劫”的超级源边，转化为单源最短路问题，最后取“已用免费”层最短路的最大值。

**关键步骤**

1. **状态扩展**  
   将每个岛屿 \(i\) 拆为两层节点：\(i^{(0)}\)（未用免费）与 \(i^{(1)}\)（已用免费）。

2. **同层建边**  
   对每条隧道 \((u,v)\) 权重 \(w\)，在层0和层1分别添加双向边 \((u\leftrightarrow v)\) 权重 \(w\)。

3. **跨层免费边**  
   在层0的 \((u^{(0)}\to v^{(1)})\) 和 \((v^{(0)}\to u^{(1)})\) 各添加一条权重 \(0\) 的边，模拟一次免费穿越。

4. **自跨层跳转**  
   在每个节点添加 \((i^{(0)}\to i^{(1)})\) 权重 \(0\) 的边，以支持“在岛上直接用免费机会”情形。

5. **超级源建模**  
   添加源点 \(S\)，对每个 \(i^{(0)}\) 添加边 \((S\to i^{(0)})\) 权重 \(a_i\)，表示不走隧道直接在岛上完成渡劫的消耗。

6. **跑 Dijkstra**  
   在包含 \(2n+1\) 个节点的分层图上，从 \(S\) 出发求最短路。

7. **结果聚合**  
   答案为所有“已用免费层”节点 \(\max_{1\le i\le n} \mathrm{dist}(i^{(1)})\)。

整体复杂度：\(O((n+m)\log(n+m))\)

# D. 禁止前缀

link: https://atcoder.jp/contests/abc403/tasks/abc403_d

**标签**：计数、分组 DP、二状态 DP

**本质思路**  
将所有元素按索引对 _d_ 取模分为 _d_ 组，在每组内做二状态线性 DP：对每个值选择“删除/保留”，用 `dp0`/`dp1`
分别维护上一个位置删除或保留的最小删除数，从而计算该组最少需要删除多少元素，最终累加得答案。

**关键步骤**

1. **统计频次**  
   用 `cnt[x]` 记录每个值 x 在序列中出现的次数。
2. **处理 d=0**  
   若 _d_ == 0，则每个值只能保留一个，删除次数为 ∑(cnt[x]−1)。
3. **分组遍历**  
   对 `r` 从 0 到 _d−1_：
    - 初始化 `dp0=0, dp1=0`
    - 按 `i = r; i < A; i += d` 遍历该组所有值（A 为数值上限）：
        - 令 `c = cnt[i]`
        - `ndp0 = min(dp0, dp1) + c` （删除当前，需删 c 个）
        - `ndp1 = dp0` （保留当前，则上一个必须删）
        - 更新 `dp0=ndp0, dp1=ndp1`
    - 该组最少删除 `min(dp0, dp1)`，累加到总答案
4. **输出答案**  
   累加所有组的最少删除次数即为最终最少删除数

整体复杂度：O(n + A)，空间复杂度 O(A)

# D. ABC400-D 高桥买鱼

link: https://atcoder.jp/contests/abc400/tasks/abc400_d

**标签**：图论、0-1 BFS、最短路、网格图

**本质思路**  
将每个格子视作图的节点，邻接无墙一步移动为权值 0 边，遇墙或跨越障碍为权值 1 边，使用 0-1 BFS 在双端队列中维护最少踢墙次数

**关键步骤**

1. **建模图结构**
    - 节点：(i,j) 对应网格格点
    - 边：对四个方向尝试一步或两步移动
        - 若移动过程中未遇墙且步长=1，权值 0
        - 否则视为“踢墙”，权值 1
2. **0-1 BFS**
    - 初始化 `hit[sx][sy] = 0`，将起点 `(sx,sy)` 加入 `deque`
    - 每次从队首弹出 `(x,y)`，若为终点 `(tx,ty)`，输出 `hit[x][y]` 并结束
    - 否则对四个方向和两种步长：
        - 计算 `(nx,ny)`，若越界则 `break`
        - 若路径至此未遇墙且步长=1：
            - `hit[nx][ny] = hit[x][y]`
            - `push_front((nx,ny))`
        - 否则：
            - `hit[nx][ny] = hit[x][y] + 1`
            - `push_back((nx,ny))`
3. **输出答案**
    - 当终点首次弹出时即为最优答案
4. **复杂度**
    - 时间 O(h·w)，空间 O(h·w)

# C. 钓鱼竞赛 (Competitive Fishing)

**link**：https://codeforces.com/contest/2042/problem/C  
**标签**：贪心、后缀差分、排序

**本质思路**  
从后向前遍历字符串，维护后缀中 Bob 鱼（‘1’）与 Alice 鱼（‘0’）数量差 `sum`。只有当 `sum>0` 时，在这一位置划分一组才能为 Bob
带来正向增益，将所有这样的 `sum` 收集到 `vals` 中，排序后贪心取最大的增益，直到累计增益 ≥ k。

**关键步骤**

1. **后缀累积差分**
    - 初始化 `sum=0`，遍历 `i=n-1…1`：
      ```cpp
      sum += (s[i]=='1' ? 1 : -1);
      if (sum>0) vals.push_back(sum);
      ```
2. **贪心选组**
    - 将 `vals` 排序升序，设 `ans=1`（至少一组）。
    - 反复取出 `vals.back()`：
      ```cpp
      while (k>0 && !vals.empty()) {
        k -= vals.back();
        vals.pop_back();
        ++ans;
      }
      ```
3. **输出结果**
    - 若最终 `k>0` 则输

# P1173. 旅行计划

link: https://www.luogu.com.cn/problem/P1137

**标签**：DAG DP、拓扑排序、最长路径

**本质思路**  
将“只能从西向东”限制视作一个有向无环图（DAG），在 DAG 上对每个节点求最长可达路径长度。

**关键步骤**

1. **建图与初始化**
    - 用邻接表 `g[x]` 存储有向边 `x→y`，并用 `in[y]++` 记录每个节点的入度；
    - 数组 `dp[i]=1`，表示以节点 i 结尾的最长路径至少包含自己。

2. **拓扑排序 (Kahn 算法)**
    - 将所有 `in[i]==0` 的节点入队；
    - 依次弹出队首 `u`，并处理其每条出边 `u→v`。

3. **DP 松弛**
   ```cpp
   dp[v] = max(dp[v], dp[u] + 1);
   if (--in[v] == 0) q.push(v);

# F. 整除最长链

link: https://codeforces.com/problemset/problem/566/F

**标签**：DAG DP、筛法、数论、最长链

**本质思路**  
最大团即全互整除的元素集合，在整除关系偏序（DAG）上求最长链,变成了DAG on DP

示意图:

       3
     / | \
    v  v  v
    6  9  12
     \  |    \
      vv     v
      18     24
       \     /  \
        v   v    v
         72      48

**关键步骤**

1. **标记出现**
    - `has[i] = true` 表示元素 `i` 在输入集合中出现；
2. **初始化 DP**
    - `dp[i] = 1`，表示单个元素自成长度为 1 的链；
3. **升序枚举 & 埃氏筛**

  ```cpp
   for (int x : a) {
       // 枚举 x 的所有倍数 y
       for (int y = x * 2; y < N; y += x) {
           if (has[y])
               dp[y] = max(dp[y], dp[x] + 1);
       }
   }
 ```

# 陕西2024 C. 换座位

**link**：https://codeforces.com/gym/105257/problem/C

**标签**：拓扑排序、环检测、DAG on DP

**本质思路**  
将每位嘉宾视为节点 \(1\ldots n\)，每个目标座位视为节点 \(1\ldots2n\)，连一条有向边 \(i\to a_i\)。此图由若干「基环树」和「指向空座的树」组成。

- 对于指向空座（编号 \(>n\)）的树，用拓扑 BFS 剥离「树枝」，维护从根到当前节点的最长链长，更新到各空座。
- 对于剩下的入度 \(>0\) 的节点，即在环上，这些环上的嘉宾可以全部就座。  
  整体时间 \(O(n)\)、空间 \(O(n)\)。

**关键步骤**

1. **建图与入度统计**
    - 数组 `to[1..n]` 存储每位嘉宾的目标座位
    - `indeg[x]++` 用来统计每个节点的入度

2. **拓扑 BFS 求「最长链」**
    - 所有 `indeg[i]==0`（嘉宾）入队，设 `dist[i]=1`
    - 取出队头 \(x\)：
        - 若 `to[x]>n`，更新 `seatLen[to[x]] = max(seatLen[to[x]], dist[x])`
        - 否则
            1. `dist[to[x]] = max(dist[to[x]], dist[x]+1)`
            2. `if (--indeg[to[x]]==0)` 则入队

3. **环上节点计数**
    - BFS 结束后，所有 `1≤i≤n` 且 `indeg[i]>0` 的节点均处在环上，记作 `环上人数`

4. **答案汇总**  
   环上人数+各空座的最大链长

# G. 消失的数字

**link**：https://codeforces.com/gym/104921/problem/G

**标签**：进制转换、字符串处理、映射

**本质思路**  
将需要删除所有含 x 的自然数，等价于把数字集合 \{0,1,…,9\} 中去掉 x 后映射到 0~8，共九个“字符”，令原数在此基底下即为一个九进制数；转换为十进制并加
1 即为它在“未消失”序列中的排名。

**关键步骤**

1. **映射数字**  
   将 \(n\) 转为字符串 \(s\)，对每个字符 \(d\)：
    - 若 \(\,d>x\)，则替换为字符 \((d-1)\)
    - 否则保持不变
2. **九进制求值**  
   从高位到低位遍历映射后的 \(s\)，维护

3. **加一修正**  
   因为序列包含 \(0\)，最终排名应为 \(\text{ans}+1\)。

整体复杂度：\(O(|s|)\)，空间复杂度：\(O(|s|)\)

# A. 函数最大子段和

link: https://codeforces.com/problemset/problem/788/A

**标签**：差分、交替符号、最大子段和、Kadane、一维DP

**本质思路**  
将原数组转化为相邻差分并交替赋予正负符号，问题变为在一维数组上求最大子段和，使用Kadane算法在线性时间内完成。

**关键步骤**

构造奇偶下标开头+-差分数组,分别执行一遍Kadane算法

- 时间：\(O(n)\)
- 空间：\(O(n)\)

# D. 阿尔卡彭苹果树

link: https://codeforces.com/problemset/problem/1056/D

**标签**：树形 DP、子树统计、排序、Order‐Statistic

**本质思路**  
每个节点要幸福，当且仅当其子树中的叶子数 ≤ 颜色数。将所有节点的“需求”——子树叶子数——统计出来并排序，第 k 小的需求即为使 ≥ k
个节点幸福所需的最少颜色数。

**关键步骤**

1. **树形 DFS 统计叶子数**
    - 从根节点 1 开始递归计算每个节点叶子数量

2. **收集并排序**
    - 将 `leaf[1…n]` 放入数组，升序排序。
3. **直接取第 k 小**
    - 对于每个 k=1…n，输出排序后数组的第 k 项。

**复杂度**

- 时间：一次 DFS O(n) + 排序 O(n log n) = **O(n log n)**
- 空间：O(n)

# C. 粒子反射

**link**：<https://codeforces.com/problemset/problem/1498/C>

**标签**：动态规划、记忆化搜索、三维状态

## 本质思路

将“粒子穿透 + 衰减复制”过程抽象为三维 DP：

- 状态 `dp[i][k][d]` 表示“一个衰减度为 k 的粒子，从第 i 个平面以方向 d（0=左，1=右）射入，最终能产生的粒子总数”。
- 每到一个平面，粒子“自己继续穿透” + “产生一个 k−1 的反向副本”，两者都要计数。
- 边界 k == 1 时，不再复制，`dp[i][1][*] = 1`。

# B. 建筑公司

link: [https://codeforces.com/gym/104417](https://codeforces.com/gym/104417)

**标签**：拓扑排序、贪心、离线扫描

**本质思路**
将每个工程的“需求”当作依赖入度，满足所有需求的工程即入度为0。承接工程会增加员工（状态单调），触发其他工程入度减少，相当于在隐式依赖图上做拓扑排序。

**关键步骤**

1. **收集**：构造 `condition[t]`（工种需求列表）和 `prise[i]`（工程奖励），维护 `in[i]` 为剩余需求数。
2. **离线排序**：对每个 `condition[t]` 按需求人数排序，初始扫描一次减少可满足的入度。
3. **拓扑队列**：所有 `in[i]==0` 入队，循环取出工程，累加奖励后对相关 `condition[t]` 扫描并动态降低 `in[j]`，新 `in[j]==0`
   则入队。
4. **计数**：出队次数即为答案。

**复杂度**
令 $M=\sum m_i+\sum k_i$，$T$ 为工种种类数，总体 $O(M\log M + M\log T + n)$。

# C. Wonderful City

link: [https://codeforces.com/contest/2096/problem/C](https://codeforces.com/contest/2096/problem/C)

**标签**：动态规划、网格、状态压缩、矩阵转置

**本质思路**
将行操作与列操作对水平/垂直冲突的影响分离，分别用「对每行/列做或不做+1操作」的二状态动态规划求最小花费，再相加。

---

## 关键步骤

1. **分治冲突类型**

    * 行操作只影响垂直相邻；列操作只影响水平相邻。
    * 因此可先独立消除垂直冲突，再独立消除水平冲突。

2. **行上 DP 定义**

    * $dp[i][x]$：处理到第 $i$ 行，且对第 $i$ 行执行状态 $x\in\{0,1\}$（0=不加，1=加一）的最小成本。

3. **状态转移**
   对每一行 $i\ge2$，枚举当前 $x$ 与上一行 $y$：

    * 检查所有列 $j$ ：
      $h_{i-1,j} + y \neq h_{i,j} + x$
    * 若所有列都不等，则
      $dp[i][x] = \min(dp[i][x],\; dp[i-1][y] + x\cdot cost_i)$

4. **边界**
   $dp[1][0] = 0,\quad dp[1][1] = cost_1$

5. **求解列冲突**
   将矩阵转置，列操作视为对转置后“行”操作，复用同样的 DP 函数。

6. **合并答案**
   垂直最优 + 水平最优；若任一为无解（∞），输出 -1。

# D. 精彩的灯泡

link: [https://codeforces.com/contest/2096/problem/D](https://codeforces.com/contest/2096/problem/D)

**标签**：不变式、模2、哈希统计、坐标几何

**本质思路**
利用翻转操作对 4 个灯泡的「模 2 奇偶不变性」，分别在竖线 $x=c$ 和对角线 $x+y=c$
上统计开灯数的奇偶，从而唯一定位初始亮灯坐标 $(s,t)$。

---

## 关键步骤

1. **模 2 奇偶不变**

    * 初始只有一个灯亮 → 奇数。每次操作切换 4 盏 → 保持总开灯数奇数。
    * 操作每条竖线/对角线上的灯,每次都是改变两个,奇偶性不变,只与初始是否有灯亮着有关

2. **统计竖线奇偶确定 $s$**

    * 用哈希表 `x_cnt[x]` 记录所有开灯点的横坐标频次。
    * 唯一出现奇数次的横坐标即为宝藏的横坐标 $s$。

3. **统计对角线奇偶确定 $s+t$**

    * 用哈希表 `plus_cnt[x+y]` 记录每个对角线（主对角线族）上开灯数。
    * 唯一奇数次的键值为 $s+t$。

4. **求出 $t$**
   $t = (s+t) - s.$

---
**时间复杂度**：$O(n\log n)$（map 统计）
**空间复杂度**：$O(n)$

# E. Wonderful泰迪熊

link: [https://codeforces.com/contest/2096/problem/E](https://codeforces.com/contest/2096/problem/E)

**标签**：逆序对、贪心、模2不变、位置统计

**本质思路**
将“黑熊(B)”视作 0，“粉熊(P)”视作 1，目标排序变为二进制数组升序。

1. 统计逆序对数 $x$：每个 1 与其右侧所有 0 构成逆序。
2. 统计总 0 数 $a$ 及偶数位 0 数 $b$，目标偶数位放 0 数为 $\lfloor a/2
   floor$，差值为 $d$。
3. 需要 $d$ 次能改偶位的操作(A/C)，每次减 1 个逆序；剩余逆序数 $(x-d)$ 用 B/D 每次减 2。
4. 最终最少操作数 $(x+d)/2$。

# J. 不是一个路径查询问题

**link**：https://codeforces.com/gym/104417/problem/J

**标签**：位运算、掩码枚举、离线连通性、并查集（DSU）、二进制技巧

## 本质思路

利用“AND ≥ V”对路径上每条边的二进制位提出强制性要求，将问题化归为“在若干筛选子图中判断连通性”。

- “AND ≥ V” ⇒ 必须保持 V 中所有 1 位不被“与”掉。
- “AND > V” ⇒ 在 V 的某个 0 位抬成 1 即可。

枚举所有可能的“抬位”掩码（至多 61 种），在每个掩码对应的子图中用并查集合并，离线回答任意一张子图连通性即可。

---

## 关键步骤

1. **掩码构造**
    - 基础掩码 `mask₀ = V`。
    - 对于 V 二进制中每个为 0 的位 `bit`，构造
      ```cpp
      mask = (V & (~((1LL<<(bit+1)) - 1))) | (1LL<<bit);
      ```
      即保留高于 `bit` 的前缀、将该位抬为 1、低位清零。
    - 总共得到 `k = popcount0(V)+1 ≤ 61` 个掩码。

2. **子图建联**
    - 为每个掩码初始化一个并查集 `DSU(n)`。
    - 遍历所有边 `(u,v,w)`：若 `(w & mask) == mask`，则在该掩码子图中合并 `u,v`。
    - 复杂度约 `O(m · k · α(n))`。

3. **离线查询**
    - 对每个询问 `(x,y)`，遍历所有 `k` 个并查集：
        - 若存在某个掩码使得 `find(x)==find(y)`，则输出 **Yes**；否则输出 **No**。
    - 平均只需检查到第一次连通即可，查询复杂度 `O(k·α(n))`。

### 时间复杂度 O((m+q)·logV ·α(n))，空间 O(n·logV)

> **模块化复盘**
> 1. 定义“掩码”模板 → 提取必须为 1 的位；
> 2. 枚举抬位 → 生成所有 ≥ V 的最小掩码；
> 3. 在每个掩码子图中用 DSU → 离线判断多次连通性。

# D. 摘苹果

**link**：[https://codeforces.com/contest/2107/problem/D](https://codeforces.com/contest/2107/problem/D)

**标签**：树、直径、DFS/BFS、分治、贪心、字典序

**本质思路**
每次在当前森林中找到“字典序最大的”直径——先取最长路径 $d$，若同长再取端点编号最大的 $(u,v)$——记录 $(d,u,v)$
，并删除整条路径上的节点。删除会将森林分裂成若干子树，对每棵子树重复相同操作。由于任何两条直径必共享至少一个节点，后续直径长度严格下降，因此记录下来的 $(d,u,v)$
序列本身即字典序降序，若需要也可先收集再统一排序。

**关键步骤**

1. **维护组件队列**
   初始将 `1`（或任意节点）入 `Q`，用 `used[]` 标记已删除，`inq[]` 标记已入队。
2. **求直径**
   对每个组件根 `r`：

    * 第一次 BFS/DFS 从 `r` 找到最远节点 `x`（距离最大，遇平距取编号大）
    * 第二次 BFS/DFS 从 `x` 找到最远节点 `y`，此时 $(x,y)$ 即直径两端，长度 `d`
3. **记录答案**
   令 $`u = max(x,y)`, `v = min(x,y)`$，向结果列表 `ans` 添加 $(d,u,v)$
4. **删除路径**
   用 `parent[]` 从 `y` 回溯到 `x`，将沿途所有节点 `used[node] = true`
5. **分裂新组件**
   对删除路径上每个节点的每个邻居 `nb`：
   如果 `!used[nb] && !inq[nb]`，则以 `nb` 为根 BFS 标记整个子树并 `Q.push(nb)`
6. **结束与输出**
   当 `Q` 为空或所有节点已删除时结束。若过程中未保证顺序，可在最后对 `ans` 按降序字典序排序，然后顺序打印所有三元组。

**复杂度分析**

* 时间：O(n√n)（直径长度逐轮下降轮数 = O(√n)，每轮 BFS/DFS 扫描子树）或 O(n log n)（用优先队列优化）
* 空间：O(n)

**生成Codex条目**

用户想要将问题E（《赛季开始》）录入Codex，并且强调按之前提供的模板来处理。根据之前的要求，在Markdown格式中，应该包括标题、链接、标签、本质思路和关键步骤部分。务必确保注释代码在其他部分之前，便于复制粘贴。生成Markdown时，避免添加过多代码，仅注重综述内容。

已思考 15 秒

# E. 异构矩阵

**link**：[https://codeforces.com/contest/12/problem/E](https://codeforces.com/contest/12/problem/E)

**标签**：图论、完全图分解、完美匹配、循环赛程

**本质思路**
将完全图 $K_n$ 的边分解为 $n-1$ 个完美匹配，每个匹配对应一次“圆桌赛程”中的一轮；再用轮次编号（1…$n-1$）作为矩阵中对称位置的值，主对角置
0。

**关键步骤**

1. **编号与初始化**

    * 顶点用 $0,1,\dots,n-2$ 环形排列，顶点 $n-1$ 固定不动。
    * 构造 $n\times n$ 矩阵，先将所有对角线元素设为 0。
2. **循环配对（共 $n-1$ 轮）**

    * 每轮 $r=0\dots n-2$：

        1. 固定顶点 $n-1$ 与环上顶点 $r$ 配对，赋值 $r+1$。
        2. 对剩余 $i=1\dots \tfrac{n}{2}-1$：

           $$
           u=(r+i)\bmod(n-1),\quad
           v=(r-i+n-1)\bmod(n-1),
           $$

           配对 $(u,v)$，同样赋值 $r+1$。
    * 每轮得到一个完美匹配，确保所有边刚好被分到其中一轮。
3. **输出矩阵**

    * 按行输出，保证对称且主对角为 0。

**复杂度**

* 时间：$\displaystyle O(n^2)$ （填充 $\tfrac{n(n-1)}2$ 条边）
* 空间：$\displaystyle O(n^2)$（矩阵存储）

**写入 Codex**

根据用户的要求，我需要将解决方案按指定的格式写入 Codex。它要求使用特定的 Markdown 格式，包括问题编号、标题和详细的思路、步骤描述。同时，我需要引用相应的链接，并填写问题的标签、关键步骤等详细信息。这个格式在背景教程中已经给出了模板，包括如“**本质思路**”、“**关键步骤**”和“整体复杂度”之类的部分。我会确保按照这些指示来写 Codex 条目。


已思考 14 秒


# P3758 可乐

**link**：[https://www.luogu.com.cn/problem/P3758](https://www.luogu.com.cn/problem/P3758)

**标签**：矩阵快速幂、邻接矩阵、状态转移、图论、建模

**本质思路**
将城市和“自爆”状态统一建模到邻接矩阵中，通过矩阵快速幂在 $t$ 步后统计从初始城市到各状态（包括自爆）的路径数。

**关键步骤**

1. **拓展状态**
   构造大小为 $(n+1)\times(n+1)$ 的邻接矩阵 $A$，其中节点 $0$ 表示“已自爆”状态，节点 $1\ldots n$ 表示各城市。
2. **构造边**

   * 对于每条道路 $u\!-\!v$，设置 $A[u][v]=A[v][u]=1$。
   * 对每个城市 $i$ 设置自环 $A[i][i]=1$ 表示停留不动；设置 $A[i][0]=1$ 表示随时可以自爆；
   * 设置 $A[0][0]=1$ 保证自爆后不可逆。
3. **矩阵快速幂**
   对矩阵 $A$ 进行快速幂运算，计算出 $A^t \bmod 2017$。
4. **汇总答案**
   初始时机器人在城市 $1$，答案即为

   $$
   \sum_{i=0}^{n} (A^t)[1][i]\bmod 2017
   $$

整体复杂度：$O(n^3\log t)$，空间复杂度：$O(n^2)$ 。

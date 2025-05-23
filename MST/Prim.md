# Prim 算法：最小生成树（优先队列优化版）

## 简介

Prim 算法由 Robert C. Prim 提出，是一种贪心算法，用于在连通无向图中找到最小生成树（MST）。使用优先队列（如最小堆）优化的版本，可以将时间复杂度从 O(V^2) 降低到 O(E log V)。它从一个起始顶点开始，逐步扩展生成树，每次选择与当前生成树相连的权重最小的边加入 MST。相比 Kruskal 算法，Prim 算法更适合处理稠密图，也可以实现 Dijkstra 算法。

## 时间复杂度

- **O(E log V)**：使用优先队列优化后，复杂度由以下部分组成：
    - 优先队列操作（插入和提取最小值）：O(log V)。
    - 总共处理 E 条边，因此总复杂度为 O(E log V)。
- 相比未优化的 O(V^2) 版本，适用于稀疏图。


### 核心思想

- **贪心策略**：从一个顶点开始，每次选择与当前生成树相连的权重最小的边。
- **优先队列优化**：使用最小堆来高效选择权重最小的边。

## 算法步骤

1. **初始化**：

   - 准备两个集合：
     - 集合 A：存储已访问的顶点，初始为空（A = {null}）。
     - 集合 B：存储所有顶点（B = {all nodes}）。
   - 初始化一个优先队列（最小堆），存储与生成树相连的边，初始时将起始顶点的所有边加入队列。
   - 用于存放最小生成树中的顶点信息。

2. **选择起始顶点**：

   - 从集合 B 中选择一个顶点（如第一个顶点）加入到集合 A 中。
   - 将该顶点连接的所有边加入优先队列，记录边的权重和目标顶点。

3. **扩展生成树**：

   - 从优先队列中取出权重最小的边。
   - 如果该边的目标顶点不在集合 A 中：
     - 将目标顶点加入集合 A。
     - 将该顶点连接的所有未访问顶点（在集合 B 中）的边加入优先队列。
   - 重复此步骤，直到集合 B 为空或优先队列为空。

## 注意事项

- **适用场景**：优化后的 Prim 算法适合稀疏图，因为优先队列减少了选择最小边的开销。
- **与 Kruskal 的区别**：Prim 从顶点出发，Kruskal 从边出发；Prim 不需要显式检查环。
- **实现建议**：
  - 使用高效的最小堆实现优先队列。
  - 注意避免重复将顶点加入优先队列，可用额外数组标记已访问顶点。
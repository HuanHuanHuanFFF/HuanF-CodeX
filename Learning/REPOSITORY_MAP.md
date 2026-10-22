# 仓库材料地图

盘点日期：2026-10-22。用途是寻找旧题、模板和复习材料；当前能力判断见 [学习者档案](../LEARNER_PROFILE.md)。

## 盘点范围与边界

本次遍历排除 Git 内部数据、IDE 配置和编译目录，读取了 708 份源码（681 C++、27 Go）及既有 31 份 Markdown 的内容，提取目录、注释、标签、声明与正文线索；按专题、近期训练及历史卡点进一步核读关键实现。所有材料均可解码。它是全量内容扫描与分类核读，不是逐行正确性审计、全部编译或平台 AC 审计。

数量包含模板、相同题目的副本、空解题函数及未完成代码；发现 18 组完全相同的源码副本，额外副本共 18 份。文件数不等于题数，更不等于用户独立解决数量。以下统计是本次盘点快照，不随训练自动更新。

## 专题材料

| 入口 | 源码数 | 已定位的内容与适用场景 |
| --- | ---: | --- |
| [BIT](../BIT/) | 16 | 基本树状数组、差分、逆序对、排列 LCS 转 LIS、值域计数、离线区间去重、DFS 前后作差、分块还原插入顺序；含独立暴力校验程序 |
| [D2BIT](../D2BIT/) | 3 | 二维点改区域和；P4514 四棵二维 BIT 与二维差分推导 |
| [SegTree](../SegTree/) | 7 | 泛型单点线段树、懒标记、区间加/乘、区间 GCD、数据结构优化 DP |
| [Persistent](../Persistent/) | 2 | 可持久化数组、路径复制、历史版本点改点查 |
| [DSU](../DSU/) | 4 | 路径压缩与按秩合并、连通块大小、图的合并与位运算条件、距离事件优先队列 |
| [MST](../MST/) | 6 | Kruskal、Prim、生成森林、几何距离建边 |
| [Tree](../Tree/) | 9 | 倍增 LCA、树直径、标记点最远距离、基环树/功能图、剥链找环 |
| [Graphs](../Graphs/) | 3 | 有向欧拉路径、Hierholzer、字符串与二分图建模 |
| [DP](../DP/) | 10 | DAG 最长路/路径计数、最短路 DAG、期望递推、Kadane、位掩码枚举 |
| [MAT](../MAT/) | 6 | 矩阵乘法、快速幂、线性递推、路径计数、高斯–约旦求逆 |
| [Math](../Math/) | 4 | 线性逆元、Lucas、组合数奇偶性 |
| [Convex Hul](../Convex%20Hul/) | 4 | Andrew 凸包、周长、旋转卡壳、直径与点积最小化 |
| [Tire](../Tire/) | 3 | 字典树前缀计数、01Trie 与异或阈值查询；沿用既有目录拼写 |
| [Monotonic](../Monotonic/) | 2 | 单调栈、滑动窗口最值的单调队列 |
| [田忌赛马](../Greedy%20Tian%20Ji%E2%80%99s%20Horse%20Racing/) | 3 | 双端贪心匹配与最大/最小得分 |
| [Calendar](../Calendar/Calendar.md) | 0 | 星期与日序计算笔记 |
| [DeepSeek](../DeepSeek/) | 132 | 分类练习，细分见下表；目录名是历史命名，不代表固定教学工具或当前路线 |
| [Learning](README.md) | 7 | 当前混合训练与提示、结果、复盘记录；堆调度专题代码另在 DeepSeek 中 |
| 根目录模板 | 2 | [temp.cpp](../temp.cpp)、[temp.go](../temp.go)；不算完成题目 |

### DeepSeek 的分类覆盖

| 分类入口 | 源码数 | 复习线索 |
| --- | ---: | --- |
| [二分](../DeepSeek/Binary%20Search/) | 11 | 答案二分、可达区间、树上分块判定、排序后查找；另有训练总结 |
| [暴力枚举](../DeepSeek/Brute%20force/) | 10 | 枚举边界、频次与值域限制、剪枝 |
| [构造](../DeepSeek/Constructive/) | 8 | 置换分环、网格路径、数论构造与通信题材料 |
| [DP](../DeepSeek/DP/) | 11 | 子序列计数、前缀和状态、LCS 还原、二维 DP、状态机、括号与整除链 |
| [DP1](../DeepSeek/DP1/) | 7 | 树上背包、换根统计、分段匹配；README 为题单链接 |
| [图论](../DeepSeek/Graphs/) | 9 | 含 Floyd 子目录 3 份；分层最短路、二分图染色、欧拉路径、功能图、直径 |
| [贪心](../DeepSeek/Greedy/) | 21 | 含堆调度 5 份；排序、集合维护、区间配对、构造与交换依据 |
| [几何](../DeepSeek/Geometry/) | 2 | 三角形计数与凸包 |
| [组合数学](../DeepSeek/Math/Combinatorics/) | 4 | 乘法计数、字典序排名、划分 |
| [模拟](../DeepSeek/Implementation/) | 4 | 枚举分段、位数计数、环与网格约束 |
| [桶排序](../DeepSeek/Sort/Bucket%20Sort/) | 1 | 利用小值域频次模拟，768C |
| [三分](../DeepSeek/Ternary%20search/) | 2 | 单谷函数、凸性与上包络 |
| [双指针](../DeepSeek/Two%20Pointers/) | 1 | 1333C：前缀和去重与合法区间计数 |
| [未分类](../DeepSeek/None/) | 41 | 零散模拟、数学与构造；读取源码后再决定模型 |

## 按比赛与平台保存的材料

[Code Instrumentality Initiative](../Code%20Instrumentality%20Initiative/) 含 485 份源码。比赛文件夹可能只做了部分题，存在副本或空实现，不表示完整打过整场。

| 分区 | 源码数 | 覆盖与入口 |
| --- | ---: | --- |
| [ABC](../Code%20Instrumentality%20Initiative/ABC/) | 119 | 23 个目录：397、400、402～420、454、455；除基础题，注释与正文含树 DP、期望/状压、0-1 BFS、增量 Floyd、Trie、单调栈贡献、组合计数等材料 |
| [CF](../Code%20Instrumentality%20Initiative/CF/) | 274 | 60 个目录，含普通轮、Educational、Global 与零散题；覆盖构造、前缀和/哈希、二分、状态图最短路、博弈、树 DP、数论、扫描线等 |
| [CF gym](../Code%20Instrumentality%20Initiative/CF%20gym/) | 2 | 北航 BCPC 材料 |
| [LC](../Code%20Instrumentality%20Initiative/LC/) | 43 | daily、DP、none、双周 181、周赛 497；含 Go 实现、快照数组、双堆中位数、滑动窗口、树与子序列 DP |
| [NowCoder](../Code%20Instrumentality%20Initiative/NowCoder/) | 4 | 2025 夏令营 S1/S9；S1 的 Numb_Numbers 解题函数为空 |
| [XCPC](../Code%20Instrumentality%20Initiative/XCPC/) | 43 | 10 场材料：河北 2025、郑州 2025、河南 2022、湖南 2024、江西 2025、辽宁 2024、陕西 2025/2024、山东 2023、郑州 2024；含多源网格 BFS、几何、分层最短路、DAG 与功能图 |

长笔记 [CodeX.md](../Code%20Instrumentality%20Initiative/CodeX.md) 按题记录模型与推导；[Unsolved.md](../Code%20Instrumentality%20Initiative/Unsolved.md) 是待补材料。DeepSeek/DP/DP.md 主要是外部推荐题单，不是已完成题目清单。

## 能帮助校准的旧记录

| 旧材料 | 具体线索 | 后续如何使用 |
| --- | --- | --- |
| [P1972](../BIT/P1972.cpp) | 注释称离线按右端点排序、只保留最后出现位置的转化依赖题解；正文是 BIT 离线去重 | 与本轮“最近出现位置”的调用困难比较，先让用户重新推导 |
| [P3605](../BIT/P3605.cpp) | 注释称能想到 BIT+DFS，但遍历前后作差去除先前子树影响需要题解提示 | 检查能否从“只要当前子树增量”推出快照差分 |
| [CF1017G](../Code%20Instrumentality%20Initiative/CF/CF%201017%20d4/G.cpp) | 注释记录操作复杂度判断与想起 deque 的过程；正文维护正反分数与方向 | 复查按操作需求选择容器与增量公式 |
| [768C](../DeepSeek/Sort/Bucket%20Sort/768C.cpp) | 注释记录初学时忽视小值域；正文使用频次数组与奇偶状态模拟 | 复查从约束选择状态表示 |
| [辽宁 2024 D](../Code%20Instrumentality%20Initiative/XCPC/LiaoNingCPC2024/D.cpp) | 保留被既有代码误导、随后重写转移的注释 | 复查从状态定义独立验证边界和转移 |

这些是历史文件里的文字与实现，不核定个人经历、作者归属或当前能力。README 已注明笔记有 AI 生成内容；所有模型和证明需结合题面及实际回答使用。

## 使用注意

- 文件名和标签用于定位，必要时核对正文与题目链接。例如 LC/daily/1226.go 实际函数为 `minTimeToVisitAllPoints`，不是按该文件号能推定的题目；部分题在专题和比赛目录重复保存。
- Trie 模板的节点虽有 `link` 字段，本次读取未见失败指针构建与 AC 自动机匹配逻辑，不能把它当作已有完整 AC 自动机材料。
- 当前 CMake 会收集全部 cpp 进一个目标，而本次发现 645 份 C++ 源文件含 main 入口；这不是全仓库可直接整体编译的结构。验证与运行按单题进行，模板按实际调用场景验证。
- 后续遇到本地图未列出的算法，先检索源码、注释及长笔记，再判断是已有材料还是待补知识。材料存在与用户当前能否独立使用分别记录。

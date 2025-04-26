# 树状数组求逆序对（“统计右侧更小”版本）

> **一句话钩子**  
> 先把数组按值升序排好队；轮到某元素时，问右边**已入库**的小元素有多少：  
> `ans += BIT.query(pos+1, n);  BIT.add(pos, 1)`  
> ——「小的先上车，数右侧座位。」

---

## 0. 前置知识（30 秒回忆）

| 概念 | 极简提示 |
| --- | --- |
| 逆序对 | *i < j 且 a[i] > a[j]* |
| 树状数组 BIT | O(log n) 维护**前缀和** |
| 升序遍历 | 先处理**更小**的值，方便直接计数 |

---

## 1. 三步流程（Occam 模块化）

| 步骤 | 操作 | 复杂度 |
| --- | --- | --- |
| **① 标记坐标并排序** | 建 `vector<pair<int,int>> v`，元素 = (值, 原下标+1)。按值升序 `sort`（稳定排序可保相等值顺序）。 | O(n log n) |
| **② 遍历并计数** | 初始化 `BIT bit(n)`<br>循环 `for (值,pos) in v`：<br>`ans += bit.query(pos+1, n);`<br>`bit.add(pos,1);` | O(n log n) |
| **③ 输出** | `cout << ans;` | O(1) |

> **记忆口诀**：**“小先入库 → 数右区间 → 累加 → 入库”**

---

## 2. C++20 模板（含 λ 表达式）

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n; vector<int> t;
    BIT(int n): n(n), t(n + 1) {}
    void add(int x, int v = 1) { for (; x <= n; x += x & -x) t[x] += v; }
    int sum(int x) const { int s = 0; for (; x; x -= x & -x) s += t[x]; return s; }
    int query(int l, int r) const { return sum(r) - sum(l - 1); }
};

long long inversion_count_right_smaller(const vector<int>& a) {
    int n = a.size();
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {a[i], i + 1};              // 下标改成 1-based
    stable_sort(v.begin(), v.end(), [](auto &l, auto &r){           // 升序排值
        return l.first < r.first;
    });

    BIT bit(n);
    long long ans = 0;
    for (auto [val, pos] : v) {
        ans += bit.query(pos + 1, n);   // 右侧更小的计数
        bit.add(pos);
    }
    return ans;
}
```

---

## 3. 复杂度

- **时间**：O(n log n)  
- **空间**：O(n)

---

## 4. Debug 清单

1. **BIT 下标从 1 开始**；原数组下标需 `+1`。  
2. `query(pos+1, n)` **别漏 +1**，区间为空时返回 0。  
3. 相等元素**不算逆序**，所以必须升序且稳定排序。  
4. `ans` 用 `long long`。

---

做完后，闭眼默背：**“小先上车 → 右区间计数 → 累加 → 入库”** —— 想到这句就能瞬间复原整套算法。

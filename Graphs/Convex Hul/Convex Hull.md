已思考几秒

# 凸包速览

## 1 · 凸包定义

给定平面点集 $S$，其**凸包**（Convex Hull）是包含 $S$ 的最小凸多边形。
想像把橡皮筋套住所有点再松开，橡皮筋所在边界即为凸包。

* 记号：$\operatorname{CH}(S)$
* 性质：顶点按逆（或顺）时针严格凸，面积唯一。

---

## 2 · 叉积（Cross Product）

三点 $a,b,c$：

$
\vec{AB}=b-a,\quad \vec{AC}=c-a
$

二维叉积（3D z 分量）

$
\operatorname{cross}(a,b,c)
=(b_x-a_x)(c_y-a_y)-(b_y-a_y)(c_x-a_x)
$

| 结果 | 含义               |
| :--: | ------------------ |
| $>0$ | **左转**（逆时针） |
| $<0$ | **右转**（顺时针） |
| $=0$ | 共线               |

> **面积**　$|\operatorname{cross}|/2$ 即三角形面积。

---

## 3 · Andrew 单调链算法（$O(n\log n)$）

### 核心步骤

1. **排序**　按字典序 $(x↑,y↑)$；去重

2. **下链**　顺序遍历，若

   $
   \operatorname{cross}(p_{k-2},p_{k-1},p)\le 0
   $

   弹栈，保持左转

3. **上链**　逆序同理

4. **合并**　上下链首尾各去重，得逆时针凸包

### 伪代码

```cpp
sort(pts);                 // O(n log n)
for p : pts:               // 下链
    while low.size≥2 && cross(low[-2],low[-1],p)≤0: low.pop_back();
    low.push_back(p);
for p : reverse(pts):      // 上链
    while up.size≥2 && cross(up[-2],up[-1],p)≤0: up.pop_back();
    up.push_back(p);
low.pop_back(); up.pop_back();
hull = low + up;           // 逆时针
```

### 复杂度

* 排序 $O(n\log n)$
* 扫描 $O(n)$
* 空间 $O(n)$

---

## 4 · 为何选 Andrew？

| 维度     | 理由                          |
| -------- | ----------------------------- |
| **简洁** | 约 20 行代码，无三角函数      |
| **高效** | 常数小，纯整数运算，无精度坑  |
| **灵活** | 改 `≤`/`<` 控制是否保留共线点 |

---

## 5 · 一眼回顾

**口诀**：排序 → 下链左转 → 上链左转 → 合并
牢记 `cross > 0 ⇒ 左转`，动手画点验证，加深记忆。
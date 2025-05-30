//
// Created by 幻 on 2025/5/29.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

// Codeforces Round 1007 (Div. 2) 
/* 2071D1
 * link: https://codeforces.com/contest/2071/problem/D1
 * 标签: 前缀异或, 递归折半, 数学构造
 * 思路:
 * 1 读入前 n 项到 a[1..n], 同时计算整体异或 p = a1⊕…⊕an 和前缀异或 pre[i]
 * 2 若 n 为偶 数, 补成奇数: n++, 插入 a[n]=pre[n/2], 同步更新 pre 和 p
 * 3 扩展序列到下标 2n: 对 i 从 n+1 到 2n,
 *    - 若 i 为偶数 2k, 直接用 a[i] = pre[k]
 *    - 若 i 为奇数, 则 a[i] = a[i-1]
 *    同时同步更新 pre
 * 4 get(x) 求单点 a[x]:
 *    - 初始化 ret=0
 *    - 若 x ≤ 2n: 直接 ret^=a[x], 结束
 *    - 否则 ret^=p(跨越一层整体异或), 检查 (x/2 - n) 奇偶:
 *        若 (x/2 - n) %2 == 0 则退出循环, 否则 x >>= 1 继续折半
 *    - 返回 ret
 *
 * 时间复杂度: O(n + log x)
 * 空间复杂度: O(n)
 */
void HuanF() {
    ll n, l, r;
    int p = 0; // 整体异或
    cin >> n >> l >> r;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i]; // 读入 a[i]
        p ^= a[i]; // 累积整体异或 p
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] ^ a[i]; // 构造前缀异或 pre
    }
    // 若 n 为偶数, 补成奇数长度
    if ((n & 1) == 0) {
        ++n;
        a.emplace_back(pre[n / 2]); // 插入新元素
        pre.emplace_back(pre.back() ^ a.back()); // 更新前缀
        p ^= a.back(); // 同步更新整体异或 p
    }
    // 扩展到下标 2n
    for (int i = n + 1; i <= n << 1; ++i) {
        a.emplace_back(pre[i / 2]); // 偶数 i=2k 用 pre[k]
        pre.emplace_back(pre[i - 1] ^ a[i]); // 更新前缀
    }
    // 单点查询 lambda
    auto get = [&](int64_t x) {
        int ret = 0;
        while (true) {
            if (x <= n * 2) {
                ret ^= a[x]; // 落入预处理区
                break;
            }
            ret ^= p; // 跨越一层整体异或 p
            if ((x / 2 - n) % 2 == 0) {
                // 检查是否可直接退出
                break;
            }
            x /= 2; // 折半继续
        }
        return ret;
    };
    cout << get(l) << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

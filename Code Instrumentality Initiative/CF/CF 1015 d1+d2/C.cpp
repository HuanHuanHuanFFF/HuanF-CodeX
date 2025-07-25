//
// Created by 幻 on 2025/5/15.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* C - You Soared Afar With Grace
 * link: https://codeforces.com/problemset/problem/2084/C
 * 思路:
 * 1 构造 idxa idxb 映射表 分别定位每行的 a[i][0] b[i][1]
 * 2 检查所有元素都在长度2的小环 奇数 n 允许一个自环
 * 3 定义 work(i j) 模块 交换整行 i j 并同步更新映射
 * 4 若 n 为奇 且中点行不是自环 调用 work 将自环行换到中点
 * 5 双指针 l r 扫描 若 a[l][0]!=a[r][1] 则 j=idxb[a[l][0]] work(r j)
 * 6 输出操作序列
 * 时间复杂度 O(n) 空间复杂度 O(n)
 */
// 怎么会,怎么会,变成了屎山
void HuanF() {
    int n;
    cin >> n;
    vector<std::array<int, 2> > a(n);
    vector<int> idxa(n + 1), idxb(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        idxa[a[i][0]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][1];
        idxb[a[i][1]] = i;
    }
    int p = 0;
    if (n & 1) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (idxa[i] != idxb[a[idxb[i]][0]]) {
                cout << "-1\n";
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i][1]) {
                if (++cnt > 1) {
                    cout << "-1\n";
                    return;
                }
                p = a[i][0];
            }
        }
        if (cnt != 1) {
            cout << "-1\n";
            return;
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (idxa[i] != idxb[a[idxb[i]][0]]) {
                cout << "-1\n";
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i][0] == a[i][1]) {
                cout << "-1\n";
                return;
            }
        }
    }
    vector<PII> ans;
    ans.reserve(n);

    auto work = [&](int i, int j) {
        // 交换整行 i ↔ j
        if (i == j) return;
        swap(a[i], a[j]);
        // —— 刷新 4 个映射 —— //
        idxa[a[i][0]] = i;
        idxa[a[j][0]] = j;
        idxb[a[i][1]] = i;
        idxb[a[j][1]] = j;
        ans.emplace_back(i + 1, j + 1);
    };

    if (n & 1 && a[n / 2][0] != a[n / 2][1]) {
        work(n / 2, idxa[p]);
    }
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l][0] != a[r][1]) {
            int j = idxb[a[l][0]];
            work(r, j);
        }
        // for (int i = 0; i < n; ++i) cout << a[i][0] << " \n"[i == n - 1];
        // for (int i = 0; i < n; ++i) cout << a[i][1] << " \n"[i == n - 1];
        ++l;
        --r;
    }
    cout << ans.size() << "\n";
    for (auto &[x,y]: ans) cout << x << " " << y << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

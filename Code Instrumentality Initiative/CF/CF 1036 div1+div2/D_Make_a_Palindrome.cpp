//
// Created by 幻 on 2025/7/6.
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

constexpr bool more = true;

// EPIC Institute of Technology Round Summer 2025 (Codeforces Round 1036, Div. 1 + Div. 2) 
// D. Make a Palindrome
// 赛时做法 硬模拟 写了半个多小时
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    if (k <= 2) {
        cout << "YES\n";
        return;
    }
    auto b = a;
    std::ranges::sort(b);
    int p = b[k - 2], cnt_p = 0;
    for (int i = k - 2; i >= 0; --i) {
        if (b[i] != p) break;
        ++cnt_p;
    }
    vector<bool> is(n);
    vector<int> pal;
    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < p) {
            is[i] = true;
            pal.emplace_back(i);
            ++len;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (a[pal[i]] != a[pal[len - 1 - i]]) {
            cout << "NO\n";
            return;
        }
    }
    if (len == 0) {
        cout << "YES\n";
        return;
    }
    int l, r;
    if (len & 1) {
        l = r = pal[len / 2];
    } else {
        l = pal[len / 2 - 1];
        r = pal[len / 2];
    }
    for (int i = l + 1; i < r && cnt_p; ++i) {
        if (a[i] == p) --cnt_p;
    }
    while (cnt_p > 0 && l >= 0 && r < n) {
        --l, ++r;
        int lvp = 0, rvp = 0;
        while (!is[l] && l >= 0) {
            if (a[l] == p) ++lvp;
            --l;
        }
        while (!is[r] && r < n) {
            if (a[r] == p) ++rvp;
            ++r;
        }
        cnt_p -= std::min(lvp, rvp) * 2;
    }
    if (cnt_p <= 0) cout << "YES\n";
    else cout << "NO\n";
}

/* 2124 D.Make a Palindrome
 * link: https://codeforces.com/contest/2124/problem/D
 * 标签: 排序, 双指针, 模拟, 贪心
 * 思路:
 * 1. 将原数组复制并排序, 取第 k 小的值 p=b[k-1]
 * 2. 过滤出所有 <= p 的元素构成序列 pal
 * 3. 用双指针 l,r 同时向中间移动:
 *    - 若 pal[l]==pal[r], 则配对, 否则
 *    - 若 pal[l]==p, 跳过左侧一个 p, len--;
 *    - 若 pal[r]==p, 跳过右侧一个 p, len--;
 *    - 其余情况说明无法回文, 输出 NO
 * 4. 最后判断剩余长度 len>=k-1 即可
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF2() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    auto b = a;
    std::ranges::sort(b);
    int p = b[k - 1];
    vector<int> pal;
    for (auto x: a)
        if (x <= p) pal.emplace_back(x);
    int len = pal.size();
    int l = 0, r = len - 1;
    while (l < r) {
        if (pal[l] == pal[r])
            ++l, --r;
        else if (pal[l] == p)
            ++l, --len;
        else if (pal[r] == p)
            --r, --len;
        else {
            cout << "NO\n";
            return;
        }
    }
    if (len >= k - 1) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF2();
    return 0;
}

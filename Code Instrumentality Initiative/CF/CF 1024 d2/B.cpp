//
// Created by 幻 on 2025/5/11.
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

/* 2102B - The Picky Cat
 * link: https://codeforces.com/problemset/problem/2102/B
 * 思路:
 * 1. 由于可以将任意 ai 取反，仅需根据 |a[i]| 排序
 * 2. 中位数是第 ⌈n/2⌉ 小的元素，记 k = (n+1)/2
 * 3. 构造 (|a[i]|, i) 数组并排序
 * 4. 检查排序后前 k 个元素中是否包含原始下标 0，若包含则 YES，否则 NO
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<PII> a(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i].first = abs(x);
        a[i].second = i;
    }
    if (n == 1) {
        cout << "yes\n";
        return;
    }
    std::sort(a.begin(), a.end());
    for (int i = 0; i <= n / 2; ++i) {
        if (a[i].second == 0) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

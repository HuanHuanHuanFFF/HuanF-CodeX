//
// Created by 幻 on 2025/6/17.
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

// Codeforces Round 1032 (Div. 3) 
// D. 1709
// 逆序对数量远小于1709,把奇数移到上面,偶数移到下面,再进行冒泡排序
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<PII> ans;
    for (auto &x: a | std::views::drop(1)) cin >> x;
    for (auto &x: b | std::views::drop(1)) cin >> x;
    int cnt1 = 0, cnt2 = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] % 2 == 0) {
            for (int j = i; j <= n - 1 - cnt1; ++j) {
                ans.emplace_back(1, j);
                std::swap(a[j], a[j + 1]);
            }
            ++cnt1;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (b[i] % 2 == 1) {
            for (int j = i; j <= n - 1 - cnt2; ++j) {
                ans.emplace_back(2, j);
                std::swap(b[j], b[j + 1]);
            }
            ++cnt2;
        }
    }
    for (int i = 0; i < cnt1; ++i) {
        ans.emplace_back(3, n - i);
        std::swap(a[n - i], b[n - i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n - i + 1; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                ans.emplace_back(1, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n - i + 1; ++j) {
            if (b[j] > b[j + 1]) {
                std::swap(b[j], b[j + 1]);
                ans.emplace_back(2, j);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto &[x,y]: ans) cout << x << " " << y << "\n";
    // cout << "\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << b[i] << " ";
    // }
    // cout << "\n\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

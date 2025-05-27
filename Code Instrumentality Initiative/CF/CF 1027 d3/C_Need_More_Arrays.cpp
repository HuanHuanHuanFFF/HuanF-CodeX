//
// Created by 幻 on 2025/5/26.
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

// Codeforces Round  1027 (Div. 3) 
// C. Need More Arrays
// 先去重,然后肯定满足a1<a2<.....<an
// 如果a1+1=a2,a2+1=a3等等,都是从第一位开始最优
// 不断往后找
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a.erase(std::unique(a.begin(), a.end()), a.end());
    int ans = 1, x = 0;
    while (x < a.size()) {
        if (a[x] + 1 < a[x + 1]) ++x;
        else x += 2;
        if (x < a.size())
            ++ans;
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

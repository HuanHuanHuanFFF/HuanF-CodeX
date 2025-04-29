#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 1355B – Young Explorers
// 链接: https://codeforces.com/problemset/problem/1355/B
// 思路：
// 1. 将所有探险家按恐惧值升序排序，保证每次用最小恐惧值作组长，最省人数。
// 2. 维护 cnt=当前组人数，遍历 a[i] 时做 cnt++；
//    若 cnt >= a[i]，则以 a[i] 为组长立即成团：ans++，cnt=0。
// 3. 只需关心当前最大恐惧值，组满后重置 cnt，线性完成。
// 复杂度：排序 O(n log n) + 遍历 O(n)。
void HuanF() {
    int n, max = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::sort(a.begin(), a.end());
    int now = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        ++now;
        if (now >= a[i]) {
            now = 0;
            ++ans;
        }
    }
    cout << ans << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

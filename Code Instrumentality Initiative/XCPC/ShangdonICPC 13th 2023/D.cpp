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

void HuanF() {
    int n;
    cin >> n;
    vector<PII> p(n);
    for (auto &[v,w]: p) cin >> v >> w;
    int l = -1, r = INF;

    auto check = [&](int x) {
        vector<int> a, b;
        for (auto [v,w]: p) {
            if (v >= x) a.push_back(v - x + w);
            else b.push_back(w);
        }
        if (a.size() < b.size()) return false;
        std::sort(a.begin(), a.end(), std::greater<>());
        std::sort(b.begin(), b.end(), std::greater<>());
        for (int i = 0; i < b.size(); ++i) {
            if (a[i] < b[i]) return false;
        }
        return true;
    };

    while (l + 1 < r) {
        int mid = l + (r - l >> 1);
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

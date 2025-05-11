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

// https://codeforces.com/gym/104417/problem/G
// 贪心取最大
// 变换等式 ai-i=aj-j
// 用map映射
void HuanF() {
    int n;
    cin >> n;
    std::map<int, vector<int> > mp;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        mp[x - i].push_back(x);
    }
    ll ans = 0;
    for (auto &[idx,v]: mp) {
        std::sort(v.begin(), v.end(), std::greater<>());
        for (int i = 0; i < v.size() - 1; i += 2) {
            ans += std::max(v[i] + v[i + 1], 0);
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

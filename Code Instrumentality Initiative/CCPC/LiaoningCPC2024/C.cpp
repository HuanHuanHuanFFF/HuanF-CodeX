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

/*
 * dfs后从小到大排列功率和限制,进行比较
 * 注意可能有大于2200W的功率限制,但是总功率只有2200W
 */
void HuanF() {
    int n;
    cin >> n;
    vector<ll> power, max_power, a(n + 1);
    vector children(n + 1, vector<int>());
    for (int i = 1, f, x; i <= n; ++i) {
        cin >> f >> x;
        children[f].push_back(i);
        a[i] = x;
    }
    a[0] = 2200;
    auto dfs = [&](auto &self, int x)-> ll {
        ll xp = 0;
        for (auto &y: children[x]) {
            xp += self(self, y);
        }
        if (children[x].empty()) xp = a[x];
        else {
            power.push_back(xp);
            a[x] = std::min(a[x], 2200LL);
            max_power.push_back(a[x]);
        }
        return xp;
    };
    dfs(dfs, 0);
    max_power.push_back(2200);
    std::sort(power.begin(), power.end());
    std::sort(max_power.begin(), max_power.end());
    for (int i = 0; i < power.size(); ++i) {
        if (power[i] > max_power[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

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
constexpr int N = 1e5 + 7;

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

// Codeforces 2104C – Card Game
// Link: https://codeforces.com/contest/2104/problem/C
void HuanF() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') a.push_back(i + 1);
        else b.push_back(i + 1);
    }
    bool bob = true; // Bob 默认胜
    // 情况一：Bob 持有最大牌 n
    if (b.back() == n) {
        // Alice 只有在她持有 1 且 Bob 只持有 n 的时候能赢
        if (a[0] == 1 && b.size() == 1)
            bob = false;
    } else {
        // 情况二：Alice 持有最大牌 n
        // Alice 若持有 1 或其第二大牌大于 Bob 的最大牌，则她能赢
        if (a[0] == 1 || a.size() >= 2 && a[a.size() - 2] > b.back()) {
            bob = false;
        }
    }
    cout << (bob ? "Bob" : "Alice") << "\n";
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

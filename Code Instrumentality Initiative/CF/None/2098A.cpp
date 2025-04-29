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

void HuanF() {
    string s, ans;
    cin >> s;
    vector<int> cnt(10);
    for (int i = 0; i < 10; ++i) {
        ++cnt[s[i] - '0'];
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 9 - i; j <= 9; ++j) {
            if (cnt[j]) {
                ans += std::to_string(j);
                --cnt[j];
                break;
            }
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

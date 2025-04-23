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
 * 狗屎
 * 可以发现翻转后最多减少2次换手
 * 如果是换手为2,那么肯定是10或是010类,能够减少一次换手
 */
void HuanF() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    s = "0" + s;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != s[i - 1])++ans;
    }
    if (ans > 2) ans -= 2;
    else if (ans == 2) --ans;
    cout << ans + n << "\n";
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

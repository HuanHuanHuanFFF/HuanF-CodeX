#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;

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
 * 要使c/a!=c/b
 * 那么a!=b
 * 用hashset对数组进行去重
 * 时间复杂度O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    std::unordered_set<int> s(n<<1);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << "\n";
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

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

// 暴力枚举
// https://codeforces.com/gym/104417/problem/I
void HuanF() {
    int a, b;
    cin >> a >> b;
    bool tag = false;
    if (a == 3 || a == 12 || a == 6 || a == 9) {
        if (b == 0) tag = true;
    } else if (a == 2 || a == 5 || a == 8) {
        if (b == 2 || b == 3 || b == 5 || b == 6) tag = true;
    } else if (a == 1 || a == 4) {
        if (b >= 4 && b <= 12) tag = true;
    } else if (a == 0) {
        if (b >= 6 && b <= 20) tag = true;
    }
    cout << (tag ? "Yes" : "No");
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

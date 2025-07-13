//
// Created by 幻 on 2025/7/11.
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

constexpr bool more = true;

// Educational Codeforces Round 174 (Rated for Div. 2)
// D. Palindrome Shuffle
void HuanF() {
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] == s[r]) ++l, --r;
        else break;
    }
    if (l > r) {
        cout << "0\n";
        return;
    }
    s = s.substr(l, r - l + 1);
    l = 0, r = s.length() + 1;
    int half = l + r >> 1, n = s.length();
    vector pre(n + 1, std::array<int, 26>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            pre[i + 1][j] = pre[i][j];
        }
        ++pre[i + 1][s[i] - 'a'];
    }
    auto check = [&](int x) {
        auto cnt = pre[x];
        int d = 0;
        if (x >= half) {
            int more = 0;
            more = x - half << 1;
            for (int i = 0; i < 26; ++i) {
                cnt[i] = abs(2 * cnt[i] - pre[n][i]);
                d += cnt[i];
            }
            if (d - more <= 0) return true;
            d = 0;
            for (int i = 0; i < 26; ++i) {
                cnt[i] = abs(pre[n][i] - 2 * pre[n - x][i]);
                d += cnt[i];
            }
            return d - more <= 0;
        } else {
            auto q = pre[x + 1], p = pre[n - x], cnt2 = pre[n];
            for (int i = 0; i < 26; ++i) {
                q[i] = pre[half + 1][i] - q[i];
                cnt2[i] -= p[i];
                p[i] -= pre[half][i];
                if (q[i] != p[i] || cnt2[i] != cnt[i]) return false;
            }
            return true;
        }
    };
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

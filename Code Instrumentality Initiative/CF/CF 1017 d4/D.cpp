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

// https://codeforces.com/contest/2094/problem/D
// 模拟统计,然后根据每段的数量进行判断,注意边界条件
void HuanF() {
    string p, s;
    cin >> p >> s;
    if (p[0] != s[0]) {
        cout << "no\n";
        return;
    }
    vector<int> l, r;
    int cntL = 0, cntR = 0;
    for (int i = 0; i < p.length(); ++i) {
        if (p[i] == 'L') {
            if (cntR != 0) {
                r.push_back(cntR);
                cntR = 0;
            }
            ++cntL;
        } else {
            if (cntL != 0) {
                l.push_back(cntL);
                cntL = 0;
            }
            ++cntR;
        }
    }
    if (cntL != 0) l.push_back(cntL);
    if (cntR != 0) r.push_back(cntR);
    std::reverse(l.begin(), l.end());
    std::reverse(r.begin(), r.end());
    cntL = 0, cntR = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'L') {
            ++cntL;
            if (cntR != 0) {
                if (r.size() && cntR <= 2 * r.back() && cntR >= r.back()) {
                    cntR = 0;
                    r.pop_back();
                } else {
                    cout << "no\n";
                    return;
                }
            }
        } else {
            ++cntR;
            if (cntL != 0) {
                if (l.size() && cntL <= 2 * l.back() && cntL >= l.back()) {
                    cntL = 0;
                    l.pop_back();
                } else {
                    cout << "no\n";
                    return;
                }
            }
        }
    }
    if (cntL)
        if (l.size() && cntL <= 2 * l.back() && cntL >= l.back()) {
            l.pop_back();
        } else {
            cout << "no\n";
            return;
        }
    if (cntR)
        if (r.size() && cntR <= 2 * r.back() && cntR >= r.back()) {
            r.pop_back();
        } else {
            cout << "no\n";
            return;
        }
    if (!l.empty() || !r.empty()) cout << "no\n";
    else cout << "yes\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

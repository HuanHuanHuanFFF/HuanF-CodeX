//
// Created by 幻 on 2026/4/24.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

void init() {
    IOS();
}

constexpr bool more = true;

// Keysight Technologies Programming Contest（AtCoder Beginner Contest 454） 
// D - (xx)
void HuanF() {
    string a, b;
    cin >> a >> b;
    auto help = [](string &x) {
        vector<char> res;
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == ')') {
                int l = res.size();
                if (l >= 3 && res[l - 1] == 'x' && res[l - 2] == 'x' && res[l - 3] == '(') {
                    res.pop_back();
                    res.pop_back();
                    res.pop_back();
                    res.push_back('x');
                    res.push_back('x');
                } else res.push_back(')');
            } else res.push_back(x[i]);
        }
        return res;
    };
    auto va = help(a), vb = help(b);
    if (va == vb) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

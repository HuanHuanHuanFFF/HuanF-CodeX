//
// Created by 幻 on 2025/11/23.
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

// Codeforces Round 1066 (Div. 1 + Div. 2) 
// B. Expansion Plan 2
// https://codeforces.com/contest/2157/problem/B
// 1.观察可以发现,与8和4的顺序无关
// 2.每有一个8就会向外扩一圈
// 3.每有一个4就会在四个角落缺少,以曼哈顿距离算的圆
// 所以判断方法为,在方格内,计算到角落的曼哈顿距离
void HuanF() {
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    x = abs(x), y = abs(y);
    int l = 0, dx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '4') {
            ++l;
            ++dx;
        } else {
            ++l;
        }
    }
    if (abs(x - l) + abs(y - l) >= dx && x <= l && y <= l) {
        cout << "YES";
    } else cout << "NO";
    cout << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

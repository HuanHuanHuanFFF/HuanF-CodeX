//
// Created by 幻 on 2025/12/14.
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

constexpr bool more = false;

// Testing Round 20 (Unrated, Communication Problems) 
// A1. Encode and Decode (Easy Version)
void HuanF() {
    string s;
    cin >> s;
    if (s == "first") {
        int n;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << (char) ('a' + x - 1);
        }
        cout << "\n";
    } else {
        cin >> s;
        cout << s.size() << "\n";
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] - 'a' + 1 << " ";
        }
        cout << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

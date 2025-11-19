//
// Created by 幻 on 2025/11/17.
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

// Codeforces Round 1059 (Div. 3) 
// E. Beautiful Palindromes
// https://codeforces.com/contest/2162/problem/E
// 构造
// 构造一段不会和前文产生回文串的 x,y,z,x,y,z 循环,即可不产生任何新的回文串
// 同样,如果签名是排列,直接往后复制不会产生任何回文串
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(i);
    }
    for (auto &x: a) {
        cin >> x;
        st.erase(x);
    }
    if (st.empty()) {
        //排列
        for (int i = 0; i < k; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    } else {
        //非排列
        vector<int> nums(3);
        nums[0] = *st.begin();
        nums[2] = a[n - 1];
        for (int i = 1; i <= n; ++i) {
            if (i != nums[0] && i != nums[2])
                nums[1] = i;
        }
        for (int i = 0; i < k; ++i) {
            cout << nums[i % 3] << " ";
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

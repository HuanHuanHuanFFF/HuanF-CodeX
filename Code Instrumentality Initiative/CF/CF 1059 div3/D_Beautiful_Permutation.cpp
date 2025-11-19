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
// D. Beautiful Permutation
// https://codeforces.com/contest/2162/problem/D
// 因为每个是+1,所以可以通过两次1~n的查询获取长度len
// 那么如何用少量的查询获取更多的信息?   二分
// 二分去找右边界,因为长度已经知道了,所以知道右边界就能知道左边界
// 每次查两下,算差值是否满足len
// 满足说明可能包含,右边界要更小
// 不满足说明一定小了,要往右边找
void HuanF() {
    int n;
    cin >> n;
    int x, y;
    cout << "1 1 " << n << endl;
    cin >> x;
    cout << "2 1 " << n << endl;
    cin >> y;
    int len = y - x, l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        cout << "1 1 " << mid << " " << endl;
        cin >> x;
        cout << "2 1 " << mid << " " << endl;
        cin >> y;
        if (y - x < len) l = mid;
        else r = mid;
    }
    cout << "! " << r - len + 1 << " " << r << endl;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

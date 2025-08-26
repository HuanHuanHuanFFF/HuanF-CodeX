//
// Created by 幻 on 2025/8/24.
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

// Codeforces Round 1044 (Div. 2) 
// C. The Nether
// https://codeforces.com/contest/2133/problem/C
// 在图上先画一下,按每个点出发的最长路径叫做高度
// 沿着最长路径的高度一定是递减的
// 那么就可以想到很暴力的方法,先全部查一遍记录下来高度
// 然后再从高度最大的点,往下一个找,每次查询结果等于2就是找到了
// 这样相当于dfs,每个点最多只会遍历一次
// 第一次查询也是O(N) 符合题目要求
void HuanF() {
    int n, max = 0;
    cin >> n;
    std::map<int, vector<int> > depth;
    for (int x = 1; x <= n; ++x) {
        cout << "? " << x << " " << n << " ";
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << endl;
        int ans;
        cin >> ans;
        depth[ans].emplace_back(x);
        max = std::max(ans, max);
    }
    vector<int> ans;
    ans.reserve(n);
    ans.emplace_back(depth[max].front());
    for (int i = max; i > 1; --i) {
        int ns = 0, x = ans.back();
        for (auto &y: depth[i - 1]) {
            cout << "? " << x << " " << 2 << " " << x << " " << y << endl;
            cin >> ns;
            if (ns == 2) {
                ans.emplace_back(y);
                break;
            }
        }
    }
    cout << "! " << ans.size() << " ";
    for (auto &x: ans) cout << x << " ";
    cout << endl;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

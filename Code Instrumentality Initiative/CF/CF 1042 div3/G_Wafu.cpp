//
// Created by 幻 on 2025/8/10.
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
constexpr ll N = 2e5 + 7;

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

vector<ll> f(31, 1);

void init() {
    IOS();
    for (int i = 1; i <= 30; ++i) {
        f[i] = i + 1;
        for (int j = 0; j < i; ++j) f[i] = f[i] * f[j] % MOD;
    }
}

constexpr bool more = true;

// Codeforces Round 1042 (Div. 3) 
/* 2131G - Operations on a Set
 * link: https://codeforces.com/contest/2131/problem/G
 * 标签: 二进制模拟, 低位1, 块跳, 递归, 预处理
 * 思路:
 * 统一减一映射 T={x-1:x∈S}; 令 X(T)=∑_{v∈T}2^v
 * 一次操作等价于对 X 做二进制减一: 清除最低位1所在位 v, 并将 [0..v-1] 全置1
 * 定义 F(i): 完整清除位 i 需 2^i 次, 这 2^i 次乘积为 F(i)
 * 递推: F(0)=1; F(i)=(i+1)*∏_{j<i}F(j)
 * 证明: 做一次 i 乘 (i+1), 同时插入 [0..i-1]; 要回到这些低位全0, 必须跑完低位一个完整周期, 乘积为 ∏_{j<i}F(j)
 * 块跳: 若 k≥2^v 则乘 F(v), k-=2^v; 否则进入 dfs(v,k)
 * dfs(v,k): 先做一次 v 乘 (v+1), k--, 之后从低到高尝试对 i=0..v-1 做整块 2^i; 不足则递归到层 i
 * 正确性: 操作=二进制减一; 位 v 的周期长度为 2^v; 高位不受影响, 因此可按 v 分块并在剩余不足时仅在 [0..v] 内递归
 * 时间复杂度: 预处理 F O(L^2); 主过程 O(n logA + log^2 k), 其中 L≈30
 * 空间复杂度: O(L)
 */
void HuanF() {
    auto dfs = [&](auto &&self, int x, int k)-> ll {
        if (k == 0) return 1;
        ll ans = x + 1;
        x = std::min(x - 1, 30);
        --k;
        for (int i = 0; i <= x; ++i) {
            if (k >= 1 << i) {
                ans = ans * f[i] % MOD;
                k -= 1 << i;
            } else {
                ans = ans * self(self, i, k) % MOD;
                break;
            }
        }
        return ans;
    };
    ll n, k, ans = 1;
    cin >> n >> k;
    vector<int> s(n);
    for (auto &x: s) {
        cin >> x;
        --x;
    }
    std::ranges::sort(s);
    for (auto &v: s) {
        if (v <= 30 && k >= 1 << v) {
            k -= 1 << v;
            ans = ans * f[v] % MOD;
        } else {
            ans = ans * dfs(dfs, v, k) % MOD;
            break;
        }
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

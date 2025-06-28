//
// Created by 幻 on 2025/6/18.
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

struct Lucas {
    int p;
    vector<int> fac, ifac;

    // 构造函数：预处理 0…p-1 范围内的阶乘 fac 和逆元阶乘 ifac
    Lucas(int p): p(p), fac(p), ifac(p) {
        fac[0] = 1;
        for (int i = 1; i < p; ++i) {
            fac[i] = 1ll * fac[i - 1] * i % p;
        }
        ifac[p - 1] = p - 1;
        for (int i = p - 1; i > 0; --i) {
            ifac[i - 1] = 1ll * ifac[i] * i % p;
        }
    }

    // C(n,k)：在 n,k < p 时返回组合数 C(n,k) mod p
    ll C(int n, int k) {
        if (n < k) return 0;
        ll ans = fac[n];
        ans = ans * ifac[k] % p;
        ans = ans * ifac[n - k] % p;
        return ans;
    }

    // get(n,k)：通过 Lucas 定理分解大规模 n,k 并计算 C(n,k) mod p
    ll get(ll n, ll k) {
        ll ans = 1;
        while (n || k) {
            ans = ans * C(n % p, k % p) % p;
            n /= p;
            k /= p;
        }
        return ans;
    }
};

// P3807 【模板】卢卡斯定理/Lucas 定理
// https://www.luogu.com.cn/problem/P3807
void HuanF() {
    int n, m, p;
    cin >> n >> m >> p;
    Lucas lucas(p);
    cout << lucas.get(n + m, m) << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

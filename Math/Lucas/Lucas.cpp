//
// Created by 幻 on 2025/6/18.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/* Lucas 定理
 * link: https://oi-wiki.org/math/number-theory/combination/  (参考)
 * 标签: 数论, 组合数, 模运算
 * 思路:
 * 1. 预处理 0…p-1 范围内阶乘 fac 与逆元阶乘 ifac, 用于快速计算 C(n,k) mod p
 * 2. 对于 n,k < p 时, 可直接用 fac 与 ifac 计算 C(n,k)
 * 3. 对于大规模 n,k, 按 Lucas 定理:
 *      C(n,k) ≡ C(n%p, k%p) * C(n/p, k/p) (mod p)
 *    递归分解直到 n,k 为 0
 * 4. 逐位相乘得到最终结果
 *
 * 时间复杂度:
 *  - 预处理: O(p)
 *  - 单次查询 get(n,k): O(log_p(n))
 *
 * 空间复杂度: O(p)
 */
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

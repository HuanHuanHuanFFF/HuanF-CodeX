//
// Created by 幻 on 2025/7/29.
//
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

/*
 * 标签: 多重排列 / 阶乘进制 / 字典序排名
 * 思路:
 *   设字符串 s 长 n，可含重复字符。
 *   记 freq[c] 为各字符剩余出现次数。
 *   扫描第 i 位，累计所有比 s[i] 小且仍有剩余字符 c：
 *     - 暂减 freq[c]，剩余位置数 rem=n-i-1。
 *     - 贡献 = rem! / ∏ factorial(freq[x])。
 *   累加贡献即得 0-based 字典序 rank。
 *   时间 O(n·m) (m=不同字符数)；空间 O(m)。
 * 时间复杂度: O(n·m)
 * 空间复杂度: O(m)
 */
static ull fact[21]{
    1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,
    3628800, 39916800, 479001600, 6227020800ULL,
    87178291200ULL, 1307674368000ULL,
    20922789888000ULL, 355687428096000ULL,
    6402373705728000ULL, 121645100408832000ULL,
    2432902008176640000ULL
};

/* 返回 s 的 0-based 字典序排名（含重复字符）*/
ull rank_multiset(string s) {
    int n = s.size();
    std::map<char, int> freq;
    for (char c: s) ++freq[c];

    auto remain_perm = [&](int rem)-> ull {
        ull res = fact[rem];
        for (auto &[_c,f]: freq) res /= fact[f];
        return res;
    };

    ull rank = 0;
    for (int i = 0; i < n; ++i) {
        int rem = n - i - 1;
        for (auto &[c,f]: freq) {
            if (c == s[i]) break; // 遇到当前字符停止
            if (f == 0) continue;
            --f; // 设第 i 位取 c
            rank += remain_perm(rem); // 累加贡献
            ++f; // 回滚
        }
        --freq[s[i]]; // 固定当前位
    }
    return rank; // 0-based
}

// O(n*m) 字符串长度*不同个数数量
string kth_permutation_with_dup(string s, ll k) {
    int n = s.size();
    // 1. 统计每个字符的频次
    std::map<char, int> freq;
    for (char c: s) ++freq[c];
    // 2. 预计算阶乘
    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    // 3. 构造答案
    string ans;
    for (int pos = 0; pos < n; ++pos) {
        ll rem = n - pos - 1;
        for (auto &[c, cnt]: freq) {
            if (cnt == 0) continue;
            // 暂减一个 c，计算以 c 开头的排列数
            cnt--;
            ll tot = fact[rem];
            for (auto &[_c, f]: freq) tot /= fact[f];
            if (k < tot) {
                ans.push_back(c);
                break; // 确定此位字符为 c
            }
            // 否则跳过这批，恢复并减去已跳过的数量
            k -= tot;
            cnt++;
        }
    }
    return ans;
}

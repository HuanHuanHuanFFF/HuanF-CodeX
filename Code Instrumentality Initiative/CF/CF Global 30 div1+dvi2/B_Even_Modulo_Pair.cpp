//
// Created by 幻 on 2025/12/10.
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

// Codeforces Global Round 30 (Div. 1 + Div. 2) 
/* 2164B-Even Modulo Pair
 * link: https://codeforces.com/contest/2164/problem/B
 * 标签: 数学, 分类讨论, 构造, 暴力
 * 思路:
 * 1) 按奇偶分开; 若偶数 ≥ 2, 任取两偶数 x < y, 有 y mod x = 2*(b mod a) 为偶数, 直接输出
 * 2) 若只有一个偶数 e, 只需枚举所有比 e 小的奇数 o, 若 e % o 为偶数则 (o, e) 成解
 * 3) 否则全为奇数, 双重循环枚举奇数对 (odd[j], odd[i]) 且 j < i, 一旦 odd[i] % odd[j] 为偶数即输出
 * 4) 复杂度关键: 奇数升序为 b1 < b2 < ...,
 *    若存在 i 使得 bi+1 < 2*bi, 则 bi+1 mod bi = bi+1 - bi 为偶数, 早已返回;
 *    因此在未找到解之前必须有 bi+1 ≥ 2*bi, 推得 bt ≥ 2^{t-1} ≤ V, t ≤ 1 + log2 V,
 *    即真正参与双重循环的奇数数量 O(log V), 故整体为 O(n + (log V)^2).
 * 时间复杂度: O(n + (log V)^2)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> odd, even;
    odd.reserve(n);
    even.reserve(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x & 1) odd.emplace_back(x);
        else even.emplace_back(x);
    }
    if (even.size() > 1) {
        cout << even[0] << " " << even[1] << "\n";
        return;
    }
    n = odd.size();
    if (even.size()) {
        int x = even[0];
        for (int i = 0; i < n; ++i) {
            if (odd[i] < x) {
                if (x % odd[i] % 2 == 0) {
                    cout << odd[i] << " " << x << "\n";
                    return;
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (odd[i] % odd[j] % 2 == 0) {
                cout << odd[j] << " " << odd[i] << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

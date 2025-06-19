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

// Educational Codeforces Round 99 (Rated for Div. 2) 
/* 1455D-SequenceAndSwaps
 * link: https://codeforces.com/contest/1455/problem/D
 * 标签: 贪心, 模拟, 排序检测, 证明
 * 思路:
 *  从左向右循环
 *  每轮先判断数组是否已非降序
 *  若未排序，则找到最左第一个 a[i]>x，交换 x 与 a[i]，操作计数++
 *  重复直到数组有序或无法交换
 *
 * 关键证明（为什么一定交换最左第一个 >x 的位置）:
 *  设 i 是最左满足 a[i]>x₀ 的下标，x₀ 为当前 x。
 *  - 若你跳过 i，在 j>i 处先交换 (a[j]>x₀):
 *      • 交换后 x₁=a[j]。若 a[j]<a[i]，则 x₁<a[i]，此时位置 i 仍违序且无法回头修复 ⇒ 无法完成排序
 *      • 若 a[j]>=a[i]，则可将“先在 i 处交换、再在 j 处交换”两步对调，操作数不增，等价于贪心策略
 *  因此，最优方案必先在 i 处交换。
 *
 * 时间复杂度: O(n²)
 * 空间复杂度: O(1)
 */
void HuanF() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int cnt = 0;
    while (true) {
        bool change = false, sorted = true;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) break;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                ++cnt;
                std::swap(x, a[i]);
                change = true;
                break;
            }
        }
        if (!change) {
            cnt = -1;
            break;
        }
    }
    cout << cnt << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

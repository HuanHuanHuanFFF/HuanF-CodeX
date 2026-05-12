//
// Created by 幻 on 2026/4/25.
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

/* ABC455-D - Card Pile Query
 * link: https://atcoder.jp/contests/abc455/tasks/abc455_d
 * 标签: 倒序处理, 链表思想, 最后一次生效
 * 思路:
 * 正向模拟每次移动一整段牌会很麻烦, 因为牌堆会不断合并和拆分
 * 但最终状态中, 对每张牌 x 来说, 只有它最后一次作为 C 被移动的操作有意义
 * 如果 x 后面还会再次作为 C 被移动, 那么前面把 x 接到某张牌上的关系会被覆盖掉
 *
 * 所以倒序处理所有操作:
 * 第一次在倒序中遇到 x 作为 C, 就等价于正序中 x 最后一次被移动
 * 此时 x 会被接到 y 的上方, 记录 up[y] = x
 * 同时 moved[x] = true, 表示初始牌堆 x 最后一定为空
 *
 * 处理完后, 没有 moved 的 i 才是最终仍然非空的牌堆底部
 * 从 i 开始沿着 up 链一直往上数, 就能得到这个牌堆最终有多少张牌
 * 如果 moved[i] 为 true, 说明牌 i 已经离开了初始牌堆 i, 答案为 0
 *
 * 每条牌与牌之间的上下关系只会被确定一次, 所有链总长度为 N
 * 时间复杂度: O(N+Q)
 * 空间复杂度: O(N+Q)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<PII> cp(q);
    vector<int> up(n + 1);
    vector<bool> moved(n + 1);
    for (int i = 0; i < q; ++i) {
        cin >> cp[i].first >> cp[i].second;
    }
    for (int i = q - 1; i >= 0; --i) {
        auto [x,y] = cp[i];
        if (!moved[x]) {
            moved[x] = true;
            up[y] = x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (moved[i]) cout << 0;
        else {
            int cnt = 1, x = i;
            while (up[x]) {
                x = up[x];
                ++cnt;
            }
            cout << cnt;
        }
        cout << " ";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

//
// Created by 幻 on 2025/5/24.
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

// AtCoder Beginner Contest 407 
/* D-Domino Covering XOR
 * link: https://atcoder.jp/contests/abc407/tasks/abc407_d
 * 标签: 枚举, 位掩码DP, 位运算, 异或运算, 状态压缩
 * 思路:
 *  - 将 H×W 格子按行优先映射到 0..H*W-1 的 bit
 *  - 用 vector<int> states 存储所有多米诺覆盖方案的位掩码，初始为 {0}
 *  - 遍历每个 bit:
 *      计算行 x = bit / w，列 y = bit % w
 *      对每个 mask 尝试：
 *        * 水平放置：若 y+1<w 且 bit、bit+1 未被覆盖，则 mask | (3<<bit)
 *        * 垂直放置：若 x+1<h 且 bit、bit+w 未被覆盖，则 mask | ((1<<bit)|(1<<(bit+w)))
 *      将生成的 tmp 合并进 states
 *  - 最后遍历所有 mask:
 *      对未被覆盖的每个格子 bit，累 XOR g[bit/w][bit%w]
 *      更新 ans 为最大异或值
 * 时间复杂度: O(N·2^N)，N = h * w
 * 空间复杂度: O(2^N)
 */
void HuanF() {
    int h, w;
    cin >> h >> w;
    vector g(h, vector<ll>(w));
    for (auto &&y: g)
        for (auto &&x: y)
            cin >> x;
    ll ans = 0;
    vector<int> states{0};
    states.reserve(1 << (h * w));
    for (int bit = 0; bit < h * w; ++bit) {
        vector<int> tmp;
        int x = bit / w, y = bit % w;
        tmp.reserve(2 * states.size());
        for (auto &&mask: states) {
            int hmask = 3 << bit;
            if (y + 1 < w && !(mask & hmask)) tmp.emplace_back(mask | hmask);
            int vmask = 1 << bit | 1 << (bit + w);
            if (x + 1 < h && !(mask & vmask)) tmp.emplace_back(mask | vmask);
        }
        states.insert(states.end(), tmp.begin(), tmp.end());
    }
    for (auto &&mask: states) {
        ll x = 0;
        for (int bit = 0; bit < w * h; ++bit) {
            if (!(mask >> bit & 1))
                x ^= g[bit / w][bit % w];
        }
        ans = std::max(ans, x);
    }
    cout << ans << "\n";
}

signed main() {
    init();
    int T = 1;
    // cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

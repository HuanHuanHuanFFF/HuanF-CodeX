//
// Created by 幻 on 2025/6/22.
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

// AtCoder Beginner Contest 410 
/* F - 平衡矩形
 * link: https://atcoder.jp/contests/abc410/tasks/abc410_f
 * 标签: 枚举, 差分数组, 前缀和, 哈希
 * 思路:
 * 1  若 h>w 则转置矩阵保证 h<=w
 * 2  ofs = h*w, 构建大小 2*ofs+1 的频次数组 cnt
 * 3  枚举上边 i 和下边 j:
 *    - 维护一维差分 d[k] += (#?1:-1) 表示第 i..j 行第 k 列的 (#-.) 差值
 *    - 令 cnt[ofs] = 1, p=0
 *    - 遍历 k=0..w-1:
 *        p += d[k];  // 前缀和
 *        ans += cnt[p+ofs];
 *        cnt[p+ofs]++;
 *    - 遍历结束后清零 cnt[ofs] 及 cnt[prefix+ofs]
 * 时间复杂度: O(h^2 * w)
 * 空间复杂度: O(h*w)
 */
void HuanF() {
    int h, w;
    cin >> h >> w;
    vector a(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }
    auto change = [](vector<vector<char> > s) {
        int x = s[0].size(), y = s.size();
        vector a(x, vector<char>(y));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                a[i][j] = s[j][i];
            }
        }
        return a;
    };
    if (h > w) {
        a = change(a);
        std::swap(h, w);
    }
    int ofs = w * h;
    vector<ll> cnt(2 * w * h + 1);
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        vector<int> d(w);
        for (int j = i; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                d[k] += (a[j][k] == '#' ? 1 : -1);
            }
            ++cnt[ofs];
            int p = 0;
            for (int k = 0; k < w; ++k) {
                p += d[k];
                ans += cnt[p + ofs];
                ++cnt[p + ofs];
            }
            p = 0;
            cnt[ofs] = 0;
            for (int k = 0; k < w; ++k) {
                p += d[k];
                cnt[p + ofs] = 0;
            }
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

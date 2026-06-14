//
// Created by 幻 on 2026/6/14.
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

template<typename T>
struct BIT {
    vector<T> t;
    int n;

    BIT(int n): t(n + 1), n(n) {
    }

    int lowbit(int x) { return x & -x; }

    void set(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            t[i] = std::max(t[i], x);
        }
    }

    int get(int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            ans = std::max(ans, t[i]);
        }
        return ans;
    }
};

constexpr bool more = false;

/* P4309 [TJOI2013] 最长上升子序列
 * link: https://www.luogu.com.cn/problem/P4309
 * 标签: 分块, 树状数组, LIS
 * 思路:
 * 题目每次把数字 i 插入到位置 pos, 要求输出每次插入后的 LIS 长度
 * 直接边插入边求 LIS 很难, 因为插入会改变序列位置
 * 先用分块数组模拟所有插入, 还原最终序列 num
 * 分块的作用是快速按位置定位, 找块 O(n / B), 块内插入 O(B), 取 B 约为 sqrt(n)
 * 得到最终序列后, 用树状数组求每个数字 x 作为结尾时的 LIS 长度 len[x]
 * 转移为 len[x] = max(len[y]) + 1, 其中 y < x 且 y 在 x 前面出现
 * 由于按最终序列从左到右扫描, 树状数组里只保存已经出现过的数字, 所以查询 get(x - 1) 即可得到前面所有小于 x 的最大 LIS 长度
 * 第 i 次插入后, 序列中存在的数字恰好是 1..i
 * 因此第 i 次答案就是 max(len[1..i]), 正序维护前缀最大即可
 * 时间复杂度: O(n sqrt(n) + n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    const int B = 450;
    vector<vector<int> > blocks;
    for (int i = 1; i <= n; ++i) {
        int pos;
        cin >> pos;
        bool inserted = false;
        for (int j = 0; j < blocks.size(); ++j) {
            if (pos <= blocks[j].size()) {
                inserted = true;
                blocks[j].insert(blocks[j].begin() + pos, i);
                if (blocks[j].size() >= 2 * B) {
                    vector<int> nb(blocks[j].begin() + B, blocks[j].end());
                    blocks[j].erase(blocks[j].begin() + B, blocks[j].end());
                    blocks.insert(blocks.begin() + j + 1, nb);
                }
                break;
            }
            pos -= (int) blocks[j].size();
        }
        if (!inserted) blocks.push_back({i});
    }
    vector<int> num;
    for (auto &b: blocks)
        for (auto &x: b)
            num.emplace_back(x);
    BIT<int> max_len(n);
    vector<int> len(n + 1);
    for (int i = 0; i < n; ++i) {
        max_len.set(num[i], max_len.get(num[i] - 1) + 1);
        len[num[i]] = max_len.get(num[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, len[i]);
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

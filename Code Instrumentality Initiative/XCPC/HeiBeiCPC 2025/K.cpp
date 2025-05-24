//
// Created by 幻 on 2025/5/20.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 7e17 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

/* K. UNO!
 * link: https://codeforces.com/gym/105909/problem/K
 * 思路:
 * 1、用 std::set<int> in 维护当前还在游戏中的玩家编号；
 * 2、用变量 v 表示出牌方向，v=1 为顺时针，v=-1 为逆时针；
 * 3、遍历操作串 s，遇到：
 *    ‘S’ 则标记跳过下一次出牌；
 *    ‘D’ 则标记跳过并抽 2 张牌；
 *    ‘R’ 则翻转方向 v；
 * 4、每个玩家出牌时手牌数 cnt[now]––,若变 0，则从 in 中移除（玩家出局）；
 * 5、根据 v 和当前 now，从 in.upper_bound 或 lower_bound 找到下一个要出牌的玩家；
 * 6、如果是抽牌操作，则在移动后给该玩家 cnt[next]+=2；如果是跳过操作，则再移动一次；
 *
 * 时间复杂度: O((n + m)·log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    std::set<int> in;
    for (auto &x: cnt) cin >> x;
    for (int i = 0; i < n; ++i) in.insert(i);
    string s;
    cin >> s;
    int v = 1, now = 0;
    for (auto &c: s) {
        bool stop = false, draw = false;
        if (c == 'S') {
            stop = true;
        } else if (c == 'D') {
            stop = true;
            draw = true;
        } else if (c == 'R') {
            v = -v;
        }
        if (--cnt[now] == 0) in.erase(now);
        if (v > 0) {
            if (now >= *in.rbegin())
                now = *in.begin();
            else now = *in.lower_bound(now + 1);
        } else {
            if (now <= *in.begin())
                now = *in.rbegin();
            else {
                auto it = in.lower_bound(now);
                --it;
                now = *it;
            }
        }
        if (draw) {
            cnt[now] += 2;
        }
        if (stop) {
            if (v > 0) {
                if (now >= *in.rbegin())
                    now = *in.begin();
                else now = *in.lower_bound(now + 1);
            } else {
                if (now <= *in.begin())
                    now = *in.rbegin();
                else {
                    auto it = in.lower_bound(now);
                    --it;
                    now = *it;
                }
            }
        }
    }
    for (auto &x: cnt) cout << x << "\n";
}

// 这个b链表怎么这么难用啊😅end不能当最后一个用
// 难道我还要手搓吗?感觉不如set一点
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    for (int &x: cnt) cin >> x;

    std::list<int> players;
    for (int i = 0; i < n; ++i) players.push_back(i);
    auto it = players.begin(); // 当前出牌玩家
    int v = 1; // 1=顺时针, -1=逆时针
    string s;
    cin >> s;

    auto step = [&](auto &itr) {
        // ⬅️ 统一“走一步”
        if (v > 0) {
            ++itr;
            if (itr == players.end()) itr = players.begin();
        } else {
            if (itr == players.begin()) itr = players.end();
            --itr;
        }
    };

    for (char c: s) {
        bool stop = false, draw = false;
        if (c == 'S') stop = true;
        else if (c == 'D') {
            stop = true;
            draw = true;
        } else if (c == 'R') v = -v;

        int cur = *it;
        --cnt[cur]; // 打出一张

        /* ----------- 玩家手牌为 0 → 删除 ----------- */
        if (cnt[cur] == 0) {
            // 先找“下一位”迭代器，再删当前
            auto nxt = it;
            step(nxt); // 方向一致地走一步
            players.erase(it); // 只删当前，不影响 nxt
            it = nxt; // 转到下一位
        } else {
            step(it); // 正常走一步
        }

        if (draw) cnt[*it] += 2; // 抽两张
        if (stop) step(it); // 跳过一位
    }

    for (int x: cnt) cout << x << '\n';
}

signed main() {
    init();
    int T = 1;
    //    cin >> T;
    while (T-- > 0)
        // HuanF();
        solve();
    return 0;
}

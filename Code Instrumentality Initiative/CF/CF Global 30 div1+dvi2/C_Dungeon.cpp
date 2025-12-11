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
/* 2164C - Dungeon
 * link: https://codeforces.com/contest/2164/problem/C
 * 标签: 贪心, 排序, 小根堆, multiset/有序集合, 两阶段处理
 * 思路:
 * 1. 阶段划分
 *    先杀 ci>0 的怪(阶段1), 因为这类操作可能产出更强的剑; ci=0 的怪(阶段2)不会产出新剑, 推迟不亏
 *    证明: 若先做 j(ci=0) 再做 k(ci>0), 做 j 不改变可用剑集合, 故可将 j 延后到 k 之后
 * 2. 阶段1顺序
 *    按 bi 升序处理
 *    证明: 相邻两次若 bi>bj, 则用于 i 的剑必能杀 j, 且新剑伤害不降, 交换(i,j)不劣
 * 3. 阶段1用剑策略
 *    每次用能杀死当前怪的最小剑; 若最小剑仍<bi, 将其移出阶段1备用
 *    证明(支配): 设可用剑多重集为 S, 对同一怪用小剑 x 或大剑 y(x<y) 的结果多重集分别为 A,B
 *      - 若 ci<=x: A=B
 *      - 若 x<ci<=y: A 将某元素提升到 ci, B 不变, 故 A 逐位≥B
 *      - 若 ci>y: A 与 B 仅在区间[p,q)发生右移/替换, A 逐位≥B
 *    因而用最小可行剑不劣
 * 4. 阶段2策略
 *    顺序无关; 依次用当前最小可行剑匹配任意 bi
 *    证明: 阶段2每把剑最多用一次, 用更小的剑完成一次匹配, 只会为后续留下“更不差”的集合
 * 5. 实现
 *    - 小根堆维护可用剑; 遍历阶段1的怪(按 bi 升序):
 *        弹出堆顶 t, 若 t<bi 则丢入备用堆/数组(阶段2用), 直至 t>=bi 或堆空;
 *        若 t>=bi, 杀之并将 max(t,ci) 重新入小根堆
 *        若堆空, 阶段1终止, 剩余 bi 归入阶段2
 *    - 阶段2: 汇总当前全部剑与所有 ci=0 的 bi; 排序后二指针/有序表匹配, 能杀则计数+1
 * 6. 复杂度
 *    时间复杂度: O((n+m)log n)
 *    空间复杂度: O(n+m)
 */
void HuanF() {
    int n, m;
    cin >> n >> m;
    std::priority_queue<int, vector<int>, std::greater<> > heap1, heap2;
    vector<int> b(m), c(m);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        heap1.emplace(x);
    }
    for (auto &x: b) cin >> x;
    for (auto &x: c) cin >> x;

    vector<PII> st1;
    vector<int> last;
    last.reserve(m);
    for (int i = 0; i < m; ++i) {
        if (c[i] > 0)
            st1.emplace_back(b[i], c[i]);
        else last.emplace_back(b[i]);
    }
    std::ranges::sort(st1);
    int ans = 0;
    for (auto &[x,y]: st1) {
        while (heap1.size()) {
            auto t = heap1.top();
            heap1.pop();
            if (x <= t) {
                ++ans;
                heap1.emplace(std::max(y, t));
                break;
            }
            heap2.emplace(t);
        }
        if (heap1.empty()) last.emplace_back(x);
    }
    while (heap1.size()) {
        heap2.emplace(heap1.top());
        heap1.pop();
    }
    std::ranges::sort(last);
    for (int i = 0; i < last.size() && !heap2.empty();) {
        if (heap2.top() >= last[i]) ++ans, ++i;
        heap2.pop();
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

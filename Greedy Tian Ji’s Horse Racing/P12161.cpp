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

/* P12161-研发资源分配
 * link: https://acm.lanqiao.cn/problem.page?gpid=T12161
 * 思路:
 *   1 打包对方提交数据为 node(val=等级, pos=天数)
 *   2 按 val 降序排序, 使得优先处理对方高等级
 *   3 初始化 sum = 1+2+...+n, 表示我方若全胜所有天的总得分
 *   4 枚举 i 从 0 到 n-1: 将第 i 个最高等级的天数作为牺牲天
 *     4.1 sum -= pos, 表示去除这天的可赢得分
 *     4.2 candidate = sum - pos, 表示剩余全赢得分减去牺牲一天的损失
 *     4.3 ans = max(ans, candidate)
 *   5 输出 ans，即最大净差值
 * 时间复杂度 O(n log n)  排序为主
 * 空间复杂度 O(n)
 */
void HuanF() {
    ll n;
    cin >> n;
    vector<PII> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    std::sort(p.begin(), p.end(), std::greater<>());
    ll sum = (1 + n) * n / 2, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum -= p[i].second; // 减去牺牲天的可赢分
        ans = std::max(ans, sum - p[i].second); // 计算剩余全赢分减去牺牲损失
    }
    cout << ans;
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

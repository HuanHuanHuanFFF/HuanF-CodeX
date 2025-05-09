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

/* 2590C - Sports Betting
 * link: https://vjudge.net/problem/CodeForces-2590C
 * 思路:
 *   1 统计每个下注日期 day 的学生数量 cnt[day]
 *   2 如果存在某天下注数 >= 4，可分别预测 (0,0),(0,1),(1,0),(1,1)，必胜
 *   3 将所有有下注的天号按升序装入数组 a
 *   4 在每个 "天号连续" 的子段中，统计下注 >=2 的天数 cnt2
 *      - 若 cnt2 >= 2，则可选该子段首尾两天作为端点，中间天均有下注，构造赢的预测方案
 *   5 上述两者均不满足，则无必胜策略
 * 时间复杂度: O(n + m) (m 为不同天数)，排序或 map 遍历均为 O(n log n)
 * 空间复杂度: O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    std::map<int, int> cnt;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        ++cnt[x];
    }
    for (auto &[x,c]: cnt) {
        if (c >= 4) {
            cout << "yes\n";
            return;
        }
    }
    // 条件二：在任意连续天段中，下注 >=2 的天数是否 >=2
    vector<PII> a(cnt.begin(), cnt.end());
    int m = a.size();
    for (int i = 0; i < m;) {
        int j = i;
        int cnt2 = a[j].second >= 2;
        // 扩展连续段 [i..j]
        while (j + 1 < m && a[j + 1].first == a[j].first + 1) {
            j++;
            if (a[j].second >= 2)
                cnt2++;
        }
        if (cnt2 >= 2) {
            cout << "Yes\n";
            return;
        }
        i = j + 1;
    }
    cout << "no\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

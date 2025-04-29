#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void open(char s[]) {
    freopen(s, "r",stdin);
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Codeforces 1334B – Middle Class
// Link: https://codeforces.com/contest/1334/problem/B
// 思路：
// 为了让选出的 k 个元素平均值 ≥ x，必须满足 ∑选中元素 ≥ k·x。
// 贪心地从最大的元素开始往下选：
//   - 维护已选元素个数 cnt 和它们的总和 sum；
//   - 尝试加入当前最大元素 a[i]，若 sum + a[i] ≥ (cnt+1)·x，则接收它（sum+=a[i], cnt++）
//   - 很好理解,先富带后富嘛
//   - 否则停止，因为再加更小的元素只会更难满足条件。
// 最后 cnt 就是能满足平均值 ≥ x 的最大 k。
// 时间复杂度：O(n log n) 排序 + O(n) 遍历。
void HuanF() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &y: a) cin >> y;
    std::sort(a.begin(), a.end());
    ll cnt = 0, sum = 0, r = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (sum + a[i] >= x * (cnt + 1)) {
            sum += a[i];
            ++cnt;
        } else break;
    }
    cout << cnt << "\n";
}

signed main() {
    IOS();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

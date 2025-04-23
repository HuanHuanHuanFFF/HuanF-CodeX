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

/*
 * 3个数组的中位数的中位数小于k
 * 小于k的数要和大于k的数一样多
 * 怎么计数?
 * 把小于等于k的数换成-1,大于k的数换成1,那么小于等于k的数区间和一定小于等于0
 * 那么至少两个区间和小于等于0
 * 只要能找到两个
 * 3种情况     1  2    2 3     1 3
 */
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i] > k ? 1 : -1;
        pre[i] = pre[i - 1] + a[i];
    }
    //有两段区间和为0
    if (std::count(pre.begin() + 1, pre.end() - 1, 0) >= 2
        || std::count(pre.begin() + 2, pre.end() - 1, pre[n]) >= 2) {
        cout << "YES\n";
        return;
    }
    //1 2情况存在pre[r]<0则必有1~r两个区间<=0 同理
    if (*std::min_element(pre.begin() + 2, pre.end() - 1) < 0
        || *std::max_element(pre.begin() + 1, pre.end() - 2) > pre[n]) {
        cout << "YES\n";
        return;
    }
    //1 3情况
    int l = 1, r = n - 1;
    while (l < r && pre[l] > 0)++l;
    while (l < r && pre[r] < pre[n])--r;
    if (l < r) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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

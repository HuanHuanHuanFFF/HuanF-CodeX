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
constexpr int N = 1e5 + 7;

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

// Codeforces 2104B – Move to the End
// Link: https://codeforces.com/contest/2104/problem/B
// 思路：
// 1. 预处理 suf[i]=∑a[i..n-1]（后缀和），pm[i]=max(a[0..i-1])（前缀最大）。
// 2. 对于每个 k（1..n），最后 k 个数最优是：
//    · k-1 个原序列末尾元素 ⇒ suf[n-k+1]
//    · 加上把前缀中最大值移到末尾 ⇒ pm[n-k+1]
//    合并得 ans[k]=suf[n-k+1]+pm[n-k+1]。
// 时间 O(n)，空间 O(n)。
void HuanF() {
    int n;
    cin >> n;
    vector<ll> a(n);
    std::map<ll, int> map; //map模拟维护前缀最大值数组
    for (auto &x: a) {
        cin >> x;
        ++map[x];
    }
    vector<ll> cp = a;
    std::sort(cp.begin(), cp.end());
    ll sum = 0;
    int r = n - 1;
    cout << cp[r] << " ";
    for (int i = n - 1; i > 0; --i) {
        --map[a[i]];
        while (!map[cp[r]]) {
            //没有就删掉
            cp.pop_back();
            --r;
        }
        sum += a[i];
        cout << sum + cp.back() << " ";
    }
    cout << "\n";
}

signed main() {
    IOS();
    open("Main/example.txt");
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

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

// Phoenix and Beauty (1348B)
// 链接: https://codeforces.com/problemset/problem/1348/B
//
// 思路：要让所有长度为 k 的子数组和相同，等价于——
//  1. 每个长度 k 的窗口里，元素的「multiset」（出现次数）都要一样；
//  2. 而窗口往右滑一格丢掉第 1 个、加入第 k+1 个，掉谁加谁都不该改变 multiset，
//     这正说明数组得是长度 k 的周期：b[i] = b[i+k]。
// 所以我们需要把原始数组 a 补充/扩展成一个周期为 k 的数组 b，
// 且它包含 a 作为子序列。唯一的障碍是——a 里到底有多少个**不同**的数？记为 d。
//
// 如果 d>k，根本没法在一个周期 k 里放下 a 的所有不同值，直接输出 -1。
// 如果 d≤k，周期里只要先放下 a 中所有不同值（任意顺序），再随便用 a[0]（或其他已知值）"
// 填满到恰好 k 个，就得到了长度 k 的「基本块」T。然后复制 n 次：
//    b = T, T, T, … (共 n 段)// 这样 b 自然长度 m = n·k，包含 a 作为子序列，且它是 k 周期的，所有窗口和相同。
// 时间：O(n + k)；空间：O(n + k)。
// T里面一定包含了 a 中出现过的 每一个不同元素，而且我们把 T 重复 了 n 次,所以T一定包含了a作为子序列
void HuanF() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    std::set<int> s(a.begin(), a.end());

    // 1. 收集不同元素
    if (s.size() > k) {
        cout << "-1\n";
        return;
    }

    // 2. 构造基本块 T（长度 k）
    //    先把所有 S 中的元素放进 T，再用 S[0] 填满
    vector<int> t(s.begin(), s.end());
    for (int i = t.size(); i < k; ++i) {
        t.push_back(*s.begin());
    }

    // 3. 重复 n 次输出
    cout << n * k << "\n";
    for (int i = 0; i < n; ++i) {
        for (auto &x: t) cout << x << " ";
    }
    cout << "\n";
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

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

template<typename T>
struct BIT {
    int n;
    vector<T> t;

    explicit BIT(int n): n(n), t(vector<T>(n + 1)) {
    }

    int lowbit(int x) { return x & -x; }

    //单点修改
    void add(int x, ll val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            t[i] += val;
        }
    }

    //查询前缀和
    ll pre_sum(int x) {
        ll ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ans += t[i];
        }
        return ans;
    }

    //查询闭区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

// Codeforces 1843E – Tracking Segments
// Link: https://codeforces.com/problemset/problem/1843/E
//
// 思路（模块化 + 奥卡姆剃刀）：
// 1. **答案二分**：对操作次数 k 二分，寻找最小 k 使得某段 [l,r] 上 1 的数量 > 0 的数量。
//2. **维护前 k 次赋值**：用树状数组 BIT 记录前 k 步中每个位置是否被置 1。
//   - 初始化时把前 mid 步 add(x, +1)，
//   - 调整时根据上一次 mid 和新 mid 差值增减 BIT。
//3. **check(k)**：遍历所有 m 段
//     • len = r[i]-l[i]+1
//     • ones = BIT.query(l[i], r[i])
//     如果 2*ones > len，则立即可行返回 true。
//4. **二分模板**：
//     le = 0, ri = q+1
//     while (ri - le > 1):
//       mid = (le + ri) / 2
//       调整 BIT 到前 mid 步的状态
//       if check(mid) ri = mid; else le = mid;
//5. **输出**：若 ri == q+1 输出 -1，否则输出 ri。
//
// 复杂度：O((n+m + q)·log n + q·log q)，对 n,m,q ≤1e5 均可接受。
// ----------------------GPT------------------------
// 答案显然是单调的,可以二分
// 二分时需要快速修改并查询前缀和
// 我去,这不是我们树状数组吗?
// 双指针?感觉不如我们树状数组优雅
// logN直接横着走
void HuanF() {
    int n, m, q;
    cin >> n >> m;
    vector<int> l(m + 1), r(m + 1);
    BIT<int> bit(n);
    for (int i = 1; i <= m; ++i) {
        cin >> l[i] >> r[i];
    }
    cin >> q;
    vector<int> change(q + 1);
    for (int i = 1, x; i <= q; ++i) {
        cin >> x;
        change[i] = x;
        if (i <= (q + 1 >> 1)) bit.add(x, 1);
    }

    auto check = [&](int x) {
        for (int i = 1; i <= m; ++i) {
            int len = r[i] - l[i] + 1;
            int query = bit.query(l[i], r[i]);
            if (query << 1 > len) return true;
        }
        return false;
    };

    int le = 0, ri = q + 1, last = le + ri >> 1;
    while (le + 1 < ri) {
        int mid = le + ri >> 1;
        if (mid < last) {
            for (int i = mid + 1; i <= last; ++i) {
                bit.add(change[i], -1);
            }
        } else if (mid > last) {
            for (int i = last + 1; i <= mid; ++i) {
                bit.add(change[i], 1);
            }
        }
        last = mid;
        if (check(mid)) ri = mid;
        else le = mid;
    }
    cout << (ri == q + 1 ? -1 : ri) << "\n";
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

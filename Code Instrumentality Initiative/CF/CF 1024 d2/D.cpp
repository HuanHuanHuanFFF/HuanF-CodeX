//
// Created by 幻 on 2025/5/11.
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


/* 2102D - 四重奏交换
 * link: https://codeforces.com/problemset/problem/2102/D
 * 思路:
 * 1 将原排列拆分为奇数下标和偶数下标两个子序列
 * 2 操作只在长度为4的块内交换，对每个子序列等价于成对相邻置换
 *   因此子序列内部可以任意排序 但逆序对总数的奇偶性保持不变
 * 3 分别用归并统计法计算奇序列和偶序列的逆序对 inv1 inv2
 * 4 对两个子序列分别排序 得到最小字典序的候选序列
 * 5 若(inv1 mod2) != (inv2 mod2) 则通过在同一子序列末尾交换最后两个元素来修正总置换奇偶性
 * 6 交替合并奇偶序列输出 即为字典序最小且可达的排列
 * 时间复杂度: O(n log n)
 * 空间复杂度: O(n)
 */
// 使用归并排序实现
void HuanF() {
    int n;
    cin >> n;
    vector<int> odd, even, a(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        if (i & 1) odd.push_back(x);
        else even.push_back(x);
    }
    auto merge = [](auto &&self, vector<int> &a, int l, int r)-> ll {
        ll ans = 0;
        if (l != r) {
            int mid = l + r >> 1;
            ans += self(self, a, l, mid);
            ans += self(self, a, mid + 1, r);
            int i = l, j = mid + 1;
            vector<int> t;
            t.reserve(r - l + 1);
            while (i <= mid && j <= r) {
                if (a[i] < a[j]) {
                    t.push_back(a[i]);
                    ++i;
                } else {
                    t.push_back(a[j]);
                    ++j;
                    ans += mid - i + 1;
                }
            }
            while (i <= mid) t.push_back(a[i++]);
            while (j <= r) t.push_back(a[j++]);
            for (int k = 0; k < t.size(); ++k) a[l + k] = t[k];
        }
        return ans;
    };
    ll inv1 = merge(merge, odd, 0, odd.size() - 1);
    ll inv2 = merge(merge, even, 0, even.size() - 1);
    int i1 = 0, i2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) a[i] = odd[i1++];
        else a[i] = even[i2++];
    }
    if ((inv1 & 1) != (inv2 & 1)) {
        std::swap(a[n - 2], a[n]);
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << "\n";
}

// 使用BIT实现
void HuanF2() {
    int n;
    cin >> n;
    vector<int> odd, even, a(n + 1);
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        if (i & 1) odd.push_back(x);
        else even.push_back(x);
    }
    BIT<int> bit1(n), bit2(n);
    ll inv1 = 0, inv2 = 0;
    for (int i = odd.size() - 1; i >= 0; --i) {
        inv1 += bit1.pre_sum(odd[i] - 1);
        bit1.add(odd[i], 1);
    }
    for (int i = even.size() - 1; i >= 0; --i) {
        inv2 += bit2.pre_sum(even[i] - 1);
        bit2.add(even[i], 1);
    }
    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());
    int i1 = 0, i2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) a[i] = odd[i1++];
        else a[i] = even[i2++];
    }
    if ((inv1 & 1) != (inv2 & 1)) {
        std::swap(a[n], a[n - 2]);
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << "\n";
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF2();
    return 0;
}

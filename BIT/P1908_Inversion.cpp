#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;
using ll = long long;
using PII = pair<int, int>;

struct BIT {
    int n;
    vector<ll> t;

    explicit BIT(int n): n(n), t(vector<ll>(n + 1)) {
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

    //查询区间和
    ll query(int l, int r) {
        return pre_sum(r) - pre_sum(l - 1);
    }
};

void IOS() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * 详见BIT_Inversion.md
 */
signed main() {
    IOS();
    int n;
    ll ans = 0;
    cin >> n;
    // 这段是归并排序的做法,没树状数组快
    // auto merge = [](auto &&self, vector<int> &a, int l, int r)-> ll {
    //     ll ans = 0;
    //     if (l != r) {
    //         int mid = l + r >> 1;
    //         ans += self(self, a, l, mid);
    //         ans += self(self, a, mid + 1, r);
    //         int i = l, j = mid + 1;
    //         vector<int> t;
    //         t.reserve(r - l + 1);
    //         while (i <= mid && j <= r) {
    //             if (a[i] <= a[j]) {
    //                 t.push_back(a[i]);
    //                 ++i;
    //             } else {
    //                 t.push_back(a[j]);
    //                 ++j;
    //                 ans += mid - i + 1;
    //             }
    //         }
    //         while (i <= mid) t.push_back(a[i++]);
    //         while (j <= r) t.push_back(a[j++]);
    //         for (int k = 0; k < t.size(); ++k) a[l + k] = t[k];
    //     }
    //     return ans;
    // };
    // vector<int> a(n);
    // for (auto &x: a) cin >> x;
    // cout << merge(merge, a, 0, n - 1);
    vector<PII> a(n);
    BIT b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x;
        a[i].y = i + 1;
    }
    sort(a.begin(), a.end());
    for (auto [num,ind]: a) {
        ans += b.query(ind + 1, n);
        b.add(ind, 1);
    }
    cout << ans;
}

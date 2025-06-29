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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/*
 * https://www.luogu.com.cn/problem/P1868
 * 按r从小到大排序,从0到len进行dp
 * 为什么是按r排序?因为这里r最重要,r前的点都算过了,通过r确定当前点最佳状态
 * 如果ri==p那么f[p]=max(f[p],f[li-1]+ri-li+1)
 * 注意不要下标越界
 */
void HuanF() {
    int n, max = 0;
    cin >> n;
    vector<PII> a(n);
    for (auto &[r,l]: a) {
        cin >> l >> r;
        max = std::max(r, max);
    }
    vector<int> f(max + 1);
    std::sort(a.begin(), a.end());
    for (int i = 1, ind = 0; i <= max; ++i) {
        f[i] = f[i - 1];
        while (ind < n && a[ind].first == i) {
            auto &[r,l] = a[ind++];
            f[i] = std::max(f[i], f[std::max(l - 1, 0)] + r - l + 1);
        }
    }
    cout << f[max];
}

signed main() {
    IOS();
    init();
    HuanF();
    return 0;
}

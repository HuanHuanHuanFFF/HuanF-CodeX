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

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

/* A. LRC and VIP
 * link: https://codeforces.com/contest/2107/problem/A
 * 思路:
 * 1 找到数组中的最大值 max 及其出现次数 cnt
 * 2 若 cnt == n，说明所有元素相同，不可能将数组分成两部分使得两部分的 gcd 不同，输出 No
 * 3 否则，将所有等于 max 的元素划分到序列 B，其余元素划分到序列 C
 *   – 此时 gcd(B) = max，因为序列 B 中所有元素都等于 max
 *   – 序列 C 中的所有元素 < max，因此 gcd(C) ≤ min(C) < max ⇒ gcd(C) ≠ gcd(B)
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int max = *std::max_element(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (max == a[i]) ++cnt;
    }
    if (cnt < n) {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) {
            if (a[i] == max) cout << 1;
            else cout << 2;
            cout << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }
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

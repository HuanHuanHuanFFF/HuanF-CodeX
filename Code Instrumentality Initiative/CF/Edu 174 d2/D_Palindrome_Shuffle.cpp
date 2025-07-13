//
// Created by 幻 on 2025/7/11.
//
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::string;

using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void init() {
    IOS();
}

constexpr bool more = true;

// Educational Codeforces Round 174 (Rated for Div. 2)
/* D-2069D
 * 标签: 二分查找 哈希 字符串 双指针
 * 思路:
 * 1. 双指针去除已匹配的最外层字符，保留中间不相等子串
 * 2. 对中间串长度 n，二分前缀/后缀长度 x，搜最小 x
 * 3. check(x):
 *    - can_pre(x):
 *        1) 检查所有完全在 [x,n-1-x] 范围内的字符对已成对
 *        2) 统计前缀 [0,x) 字符计数 cnt
 *        3) 对所有半在前半在后的对，用后缀字符扣减 cnt，若不足则 fail
 *        4) 若 x>n/2，则剩余 cnt 总和应可两两配对
 *    - 若前缀可行或反转后可行，则 check 通过
 * 4. 对 [0,n] 区间二分查找最小可行 x
 * 时间复杂度 O(n log n)，空间复杂度 O(n)
 */
void HuanF() {
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] == s[r]) ++l, --r;
        else break;
    }
    if (l > r) {
        cout << "0\n";
        return;
    }
    s = s.substr(l, r - l + 1);
    l = 0, r = s.length();
    int half = s.length() / 2, n = s.length();
    auto can_pre = [&](int x) {
        for (int i = x; i < n - x; ++i) {
            if (s[i] != s[n - i - 1]) return false;
        }
        vector<int> cnt(26);
        for (int i = 0; i < x; ++i) {
            ++cnt[s[i] - 'a'];
        }
        for (int i = 0; i < x && n - 1 - i >= x; ++i) {
            if (--cnt[s[n - 1 - i] - 'a'] < 0) return false;
        }
        if (x > half) {
            int sum = std::accumulate(cnt.begin(), cnt.end(), 0);
            if (sum & 1) return false;
        }
        return true;
    };
    auto check = [&](int x) {
        if (can_pre(x)) return true;
        std::reverse(s.begin(), s.end());
        bool ok = false;
        if (can_pre(x)) ok = true;
        std::reverse(s.begin(), s.end());
        return ok;
    };
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

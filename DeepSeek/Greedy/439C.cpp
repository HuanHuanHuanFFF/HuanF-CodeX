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

// Codeforces 439C – Devu and Partitioning of the Array
// Link: https://codeforces.com/problemset/problem/439/C
// 思路：
// 1. 将所有数按奇偶分为 odd[] 和 even[]。
// 2. 如果 odd.size() < k-p，则无法构造 k-p 个奇数组，直接 NO。
// 3. 用贪心分组：
//    (1) 先取 k-p 个奇数（各一）构造奇数组；
//    (2) 再取 p 个偶数和组：
//         • 优先用一个偶数/组；
//         • 偶数不够时，用两奇数配对；
//    若还不足 p 组，则 NO。
// 4. 将剩余所有奇数与偶数全部扔进最后一组，不改变前面各组的奇偶和属性。
// 5. 输出 YES 并依次打印每组元素。
// 狗屎贪心模拟,代码奇臭无比
void HuanF() {
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> odd, even;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if (x & 1)odd.push_back(x);
        else even.push_back(x);
    }
    if (odd.size() < k - p) {
        cout << "NO\n";
    } else {
        int more = odd.size() - (k - p);
        if (more & 1) {
            cout << "NO\n";
            return;
        }

        vector<vector<int> > group;
        for (int i = 0; i < k - p; ++i) {
            group.push_back({odd[i]});
        }
        for (int i = 0; i < std::min((int) even.size(), p); ++i) {
            group.push_back({even[i]});
        }
        if (group.size() == k) {
            for (int i = k - p; i < odd.size(); ++i) {
                group[k - 1].push_back(odd[i]);
            }
            for (int i = p; i < even.size(); ++i) {
                group[k - 1].push_back(even[i]);
            }
        } else {
            if (more / 2 + group.size() < k) {
                cout << "NO\n";
                return;
            }
            int end = INF;
            for (int i = k - p; i < odd.size(); i += 2) {
                group.push_back({odd[i], odd[i + 1]});
                if (group.size() == k) {
                    end = i;
                    break;
                }
            }
            for (int i = end + 2; i < odd.size(); ++i) {
                group[k - 1].push_back(odd[i]);
            }
        }
        cout << "YES\n";
        for (auto &g: group) {
            cout << g.size();
            for (int x: g) cout << " " << x;
            cout << "\n";
        }
    }
}

signed main() {
    IOS();
    init();
    // int T;
    // cin >> T;
    // while (T-- > 0)
    HuanF();
    return 0;
}

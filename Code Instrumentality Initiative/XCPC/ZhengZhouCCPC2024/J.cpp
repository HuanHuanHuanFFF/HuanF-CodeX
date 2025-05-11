#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
constexpr int MOD = 998244353;
constexpr int INF = 1e9 + 17;
constexpr int N = 1e7 + 7;

void init() {
}

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

std::set<int> set({0, 2, 4, 5, 6, 8});

/* J-排列与合数
 * 思路:
 *  输入5位互不相同数字字符串 s  无前导零
 *  要构造末尾 digit∈{0,2,4,5,6,8} 的排列 s' 保证合数 且 s' 无前导零
 *  1 在 i=1..3（中间三位）依次查找第一个 digit 合法的 s[i]
 *    删除第 i 位后追加到末尾  此时首位仍为原 s[0]≠'0'  无前导零
 *  2 若中间三位都不合法  则必有 s[0] 或 s[4] 合法
 *    a 若 s[0] 合法  则删除 s[0] 末尾追加  新首位为原 s[1]≠'0'
 *    b 否则 s[4] 合法  将中间任意两位交换（如 s[2]<->s[3]）  保持末位为 s[4]
 *  这样能确保末尾为合法合数末位 且首位非零
 * 时间复杂度 O(1)  空间复杂度 O(1)
 */
void HuanF() {
    string s;
    cin >> s;
    int len = s.length();
    // 尝试中间三位
    for (int i = 1; i < len - 1; ++i) {
        if (set.count(s[i] - '0')) {
            cout << s.substr(0, i) + s.substr(i + 1) << s[i] << "\n";
            return;
        }
    }
    // 中间三位都不合法
    if (set.count(s[0] - '0')) // s[0] 合法  删除首位后追加
        cout << s[1] << s[2] << s[3] << s[4] << s[0] << "\n";
    else cout << s[0] << s[1] << s[3] << s[2] << s[4] << "\n";
    // 只有 s[4] 合法  随意交换中间两位 保持末位为 s[4]
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

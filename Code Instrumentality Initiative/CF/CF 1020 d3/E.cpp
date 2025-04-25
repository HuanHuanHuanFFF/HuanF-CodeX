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

auto AC() {
    //AC!
    //WA->AC
    //TLE/MLE->AC
}

/*
 * https://codeforces.com/contest/2106/problem/E
 * 直接模拟去二分查找,控制每次查找当前位置的数字,经比较后往需要的位置靠
 * 每次能换两个数字,换一个小的一个大的
 * 还要注意把比该数字大或小的都换完了就不能再动了
 *
 * 核心:需要打乱的下标数 = max(左错向, 右错向)
 */
void HuanF() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    std::unordered_map<int, int> pos(n << 1); //用哈希表记录下标
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 0, l, r, k; i < q; ++i) {
        cin >> l >> r >> k;
        auto x = pos[k];
        //如果不在范围内直接输出-1
        if (x > r || x < l) {
            cout << -1 << " ";
        } else {
            //二分模拟
            int mid = l + (r - l >> 1), cnt1 = 0, cnt2 = 0, max = n, min = 1;
            while (mid != x) {
                if (mid < x) {
                    //在目标位置左边,要往右找,如果当前位置不行就换一个小的来
                    if (p[mid] > k) {
                        ++cnt1;
                    }
                    //当前已经至少用了一个最小的数
                    ++min;
                    l = mid + 1;
                } else {
                    //同理
                    if (p[mid] < k) {
                        ++cnt2;
                    }
                    --max;
                    r = mid - 1;
                }
                mid = l + (r - l >> 1);
            }
            //最后给cnt取max,因为每次可以交换其中一对的一大一小
            int cnt = std::max(cnt2, cnt1);
            if (min > k || max < k) cout << -1 << " ";
            else cout << cnt * 2 << " ";
        }
    }
    cout << "\n";
}

signed main() {
    IOS();
    AC();
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

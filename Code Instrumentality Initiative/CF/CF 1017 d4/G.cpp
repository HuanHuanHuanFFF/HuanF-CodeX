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

/* 2094-G
 * link: https://codeforces.com/contest/2094/problem/G
 * 思路:
 * - 使用 std::deque 支持在两端弹出与插入，模拟数组两端操作
 * - 维护四个状态变量：
 *     s    当前正向分数 ∑i·a[i]
 *     rs   反向分数  ∑(n+1−i)·a[i]
 *     sum  数组元素和 ∑a[i]
 *     head 布尔标记，true 表示当前 deque 正向，false 表示逻辑上已翻转
 * - 操作1（类型1）：弹出末尾元素 an 并插入前端
 *     正向分数变化：s  += sum − an·n
 *     反向分数变化：rs += an·n − sum
 *     deque 操作：根据 head 决定从哪端 pop，再从另一端 push
 * - 操作2（类型2）：翻转数组
 *     交换 s 与 rs；切换 head 标记
 * - 操作3（类型3）：在末端插入 x
 *     sum 增加 x
 *     正向分数 s  增加 (n+1)·x
 *     反向分数 rs 增加 sum（已包含 x）
 *     deque 操作：根据 head 决定 push_back 还是 push_front
 * - 每次查询后输出当前正向分数 s
 * 时间复杂度 O(q)；空间复杂度 O(q)
 */
// 推出公式后,开始拿了个vector模拟,用start end维护
// 结果发现操作3是O(N)的,去看题解才想起来deque😭
// 然后继续我的思路写完了
void HuanF() {
    ll s = 0, rs = 0, sum = 0; // s:正向分数, rs:反向分数, sum:元素和
    int q;
    bool head = true; // true=正向, false=逻辑翻转
    cin >> q;
    std::deque<int> a;
    for (int i = 0, opt; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            // 类型1：弹出末尾元素并插到前端（或反向时相反）
            ll an = head ? a.back() : a.front();
            // 更新分数
            s += sum - an * a.size();
            rs += an * a.size() - sum;
            // 更新 deque
            if (head) {
                a.pop_back();
                a.push_front(an);
            } else {
                a.pop_front();
                a.push_back(an);
            }
        } else if (opt == 2) {
            // 类型2：翻转数组
            std::swap(s, rs);
            head = !head;
        } else {
            // 类型3：在末端插入 x（或反向时在前端）
            int x;
            cin >> x;
            sum += x;
            s += (a.size() + 1) * x;
            rs += sum;
            if (head) a.push_back(x);
            else a.push_front(x);
        }
        cout << s << "\n";
    }
}

signed main() {
    init();
    int T;
    cin >> T;
    while (T-- > 0)
        HuanF();
    return 0;
}

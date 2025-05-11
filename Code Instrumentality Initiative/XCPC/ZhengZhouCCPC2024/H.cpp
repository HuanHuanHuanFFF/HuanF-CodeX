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

/*
    核心思路说明：
    1. 模拟插入/取出过程
       - 用 std::map<int,int> 维护当前“栈”（多重集合）中每个元素的个数
       - 用变量 all 记录当前集合的总大小
    2. 每次取出最小值
       - 如果要保证出队序列非递减，最优（也是唯一正确）策略是每次都从当前集合中取最小元素
       - 取 map.begin() 得到最小键值对 (val, cnt)
       - 如果 val < last，则代表序列必然下降，直接输出 0 并退出
    3. 累乘取出该最小值的概率
       - 当前集合大小为 all，取到最小值的概率为 cnt / all
       - 在模 MOD 下，用预处理好的 inv[all] 表示 all⁻¹ mod MOD
       - 本轮贡献： ans = ans * cnt % MOD * inv[all] % MOD
    4. 更新状态
       - last = val               // 记录本次取出的值
       - all--                    // 总大小减一
       - it->second--             // 该值的剩余个数减一
       - 如果 it->second == 0，则 mp.erase(it)
    5. 输出答案
       - 模拟完成所有 2*n 次操作后，ans 即为所求结果
*/
void HuanF() {
    int n;
    cin >> n;
    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        // 费马小定理线性求逆元公式
        inv[i] = (MOD - (MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
    ll ans = 1, last = 0, all = 0;
    std::map<int, int> map;
    for (int i = 0, x; i < n << 1; ++i) {
        cin >> x;
        if (x == -1) {
            auto it = map.begin();
            if (it->first < last) {
                cout << "0\n";
                return;
            }
            ans = ans * it->second % MOD * inv[all] % MOD;
            last = it->first;
            --it->second;
            --all;
            if (it->second == 0) {
                map.erase(it);
            }
        } else {
            ++all;
            ++map[x];
        }
    }
    cout << ans;
}

signed main() {
    IOS();
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

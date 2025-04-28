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
constexpr int N = 1e5 + 7;

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

// Codeforces 2046B – Move Back at a Cost
// Link: https://codeforces.com/problemset/problem/2046/B
// 关键点：
// 1. 元素最多移动一次
//    每个元素被“+1 且移到末尾”后，其相对顺序就固定了，继续对同一元素操作只会让它更大，不可能再影响字典序优先级。
//    因此可以假设对每个元素最多操作一次（要么不动，要么移堆一次）。
// 2. 后缀最小值标记
//    从右向左维护当前最小值 mn，若 a[i] > mn，则标记 suf[i]=true，表示该元素最终要 +1 并移至末尾。
void HuanF() {
    int n;
    cin >> n;
    vector<int> a(n), ans;
    vector<bool> suf(n, false);
    for (auto &x: a) cin >> x;
    int min = a.back();
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > min) suf[i] = true;
        min = std::min(min, a[i]);
    }
    std::priority_queue<int, vector<int>, std::greater<> > heap;
    for (int i = 0; i < n; ++i) {
        if (suf[i]) heap.push(a[i] + 1);
        else if (heap.size() && a[i] > heap.top()) heap.push(a[i] + 1);
        else ans.push_back(a[i]);
    }
    for (auto &x: ans) cout << x << " ";
    while (heap.size()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << "\n";
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

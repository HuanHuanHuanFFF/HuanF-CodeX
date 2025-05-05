#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<ll, ll>;
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

// https://atcoder.jp/contests/abc404/tasks/abc404_a
// set插入a~z,遍历字符串删除,输出一个set中的
void HuanF() {
    string s;
    cin >> s;
    std::set<char> set;
    for (int i = 0; i < 26; ++i) {
        set.insert((char) ('a' + i));
    }
    for (int i = 0; i < s.length(); ++i) {
        set.erase(s[i]);
    }
    cout << *set.begin();
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

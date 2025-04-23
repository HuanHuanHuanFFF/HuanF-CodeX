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
// https://codeforces.com/gym/105481
void HuanF() {
    std::unordered_set<string> set(1e7);
    //用hashset计算,最后直接输出set的元素数
    string s;
    while (cin >> s) {
        if (isdigit(s[0])) break;
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else s.erase(i);
        }
        set.insert(s);
    }
    int n = 0;
    for (int i = 0; i < s.size(); ++i) {
        n *= 10;
        n += s[i] - '0';
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        set.erase(s);
    }
    cout << set.size();
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

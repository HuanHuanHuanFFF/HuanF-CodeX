//
// Created by 幻 on 2025/12/14.
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
using ld = long double;
using PII = pair<int, int>;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9 + 17;
constexpr ll N = 1e7 + 7;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

void IOS() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

auto get_now() {
    return std::chrono::high_resolution_clock::now();
}

auto ms_dis(auto t2, auto t1) {
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
}

vector<char> int2char({'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
std::map<char, int> char2int;

void init() {
    IOS();
    for (int i = 0; i < 10; ++i) {
        char2int[int2char[i]] = i;
    }
}

constexpr bool more = false;

// Testing Round 20 (Unrated, Communication Problems) 
// A2. Encode and Decode (Hard Version)
// 编码解码,找到足够高效的编码方式即可
// 这里直接对应0~9数字,加上一个间隔
// 长度为10的数字直接强制隔开即可
// 其他的用x分割
void HuanF() {
    string s;
    cin >> s;
    if (s == "first") {
        int n;
        cin >> n;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            vector<char> ans;
            ans.reserve(10);
            while (x) {
                int y = x % 10;
                x /= 10;
                ans.emplace_back(int2char[y]);
            }
            for (auto &y: std::views::reverse(ans))
                cout << y;
            if (ans.size() != 10)
                cout << "x";
        }
    } else {
        cin >> s;
        string ans;
        ans.reserve(1e5);
        int cnt = 0, len = 0;
        for (auto &x: s) {
            if (x == 'x') {
                ans.append(" ");
                ++cnt;
                len = 0;
            } else {
                ans.append(std::to_string(char2int[x]));
                ++len;
            }
            if (len == 10) {
                ans.append(" ");
                len = 0;
                ++cnt;
            }
        }
        cout << cnt << "\n";
        cout << ans << "\n";
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

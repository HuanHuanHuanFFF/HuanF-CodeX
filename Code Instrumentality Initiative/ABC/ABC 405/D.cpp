//
// Created by 幻 on 2025/5/12.
//
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

// https://atcoder.jp/contests/abc405/tasks/abc405_d
// bfs
void HuanF() {
    int h, w;
    cin >> h >> w;
    string s;
    vector g(h, vector<char>(w));
    std::queue<PII> q;
    for (int i = 0; i < h; ++i) {
        cin >> s;
        for (int j = 0; j < w; ++j) {
            g[i][j] = s[j];
            if (s[j] == 'E') q.emplace(i, j);
        }
    }
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    char draw[] = {'<', '^', '>', 'v'};
    while (q.size()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && g[nx][ny] == '.') {
                g[nx][ny] = draw[i];
                q.emplace(nx, ny);
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << g[i][j];
        }
        cout << "\n";
    }
}

signed main() {
    init();
    //    int T;
    //    cin >> T;
    //    while (T-- > 0)
    HuanF();
    return 0;
}

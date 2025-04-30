#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::pair;
using std::vector;
using std::string;

using ull = unsigned long long;
using ll = long long;
using PII = pair<int, int>;
using PIII = pair<int, PII>;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e8 + 17;
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

void HuanF() {
    int h, w;
    cin >> h >> w;
    vector g(h, vector<int>(w)), hit(h, vector<int>(w, INF));
    for (int i = 0; i < h; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < w; ++j) {
            g[i][j] = s[j] == '.' ? 0 : 1;
        }
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b, --c, --d;

    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    std::deque<int> dq;
    hit[a][b] = 0;
    dq.push_front(a * w + b);
    while (!dq.empty()) {
        auto z = dq.front();
        dq.pop_front();
        if (z == c * w + d) {
            cout << hit[c][d];
            return;
        }
        auto x = z / w, y = z % w;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && hit[nx][ny] > hit[x][y]) {
                if (g[nx][ny] == 1) {
                    int nnx = x + dx[i] * 2, nny = y + dy[i] * 2;
                    if (nnx >= 0 && nnx < h && nny >= 0 && nny < w) {
                        dq.push_back(nnx * w + nny);
                        hit[nnx][nny] = hit[x][y] + 1;
                    }
                    dq.push_back(nx * w + ny);
                    hit[nx][ny] = hit[x][y] + 1;
                } else {
                    hit[nx][ny] = hit[x][y];
                    dq.push_front(nx * w + ny);
                }
            }
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

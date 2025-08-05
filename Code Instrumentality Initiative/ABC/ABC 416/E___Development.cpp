//
// Created by 幻 on 2025/8/2.
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
using PII = pair<int, int>;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e17 + 17;
constexpr int N = 1e7 + 7;

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

void init() {
    IOS();
}

constexpr bool more = false;

// AtCoder Beginner Contest 416
// E - Development
void HuanF() {
    int n, m;
    cin >> n >> m;
    vector dis(n + 1, vector<ll>(n + 1, INF));
    for (ll i = 0, a, b, c; i < m; ++i) {
        cin >> a >> b >> c;
        dis[a][b] = dis[b][a] = std::min(dis[a][b], c);
    }
    for (int i = 0; i <= n; ++i) dis[i][i] = 0;
    int t, k;
    cin >> k >> t;
    for (int i = 0, d; i < k; ++i) {
        cin >> d;
        dis[d][0] = t;
        dis[0][d] = 0;
    }
    for (int p = 0; p <= n; ++p) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dis[i][j] = std::min(dis[i][j], dis[i][p] + dis[p][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0, opt; i < q; ++i) {
        cin >> opt;
        if (opt == 1) {
            ll x, y, tt;
            cin >> x >> y >> tt;
            dis[x][y] = dis[y][x] = std::min(dis[x][y], tt);
            for (int a = 0; a <= n; ++a) {
                for (int b = 0; b <= n; ++b) {
                    dis[a][b] = std::min({
                        dis[a][b], dis[a][x] + dis[x][y] + dis[y][b], dis[a][y] + dis[y][x] + dis[x][b]
                    });
                }
            }
        } else if (opt == 2) {
            int x;
            cin >> x;
            dis[0][x] = 0;
            dis[x][0] = t;
            for (int j = 0; j <= n; ++j) {
                dis[j][x] = std::min(dis[j][0] + t, dis[j][x]);
                dis[0][j] = std::min(dis[x][j], dis[0][j]);
            }
            for (int a = 0; a <= n; ++a) {
                for (int b = 0; b <= n; ++b) {
                    dis[a][b] = std::min(dis[a][b], dis[a][0] + dis[0][b]);
                }
            }
        } else {
            ll ans = 0;
            for (int x = 1; x <= n; ++x) {
                for (int y = 1; y <= n; ++y) {
                    ans += dis[x][y] >= INF ? 0 : dis[x][y];
                }
            }
            cout << ans << "\n";
        }
    }
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

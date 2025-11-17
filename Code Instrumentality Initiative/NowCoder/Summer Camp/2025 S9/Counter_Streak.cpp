//
// Created by 幻 on 2025/8/12.
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

void init() {
    IOS();
}

constexpr bool more = false;

//  
// Counter Streak
void HuanF() {
    int n;
    scanf("%d", &n);
    // vector dp_max(3, std::map<ll, int>());
    // vector dp_min(3, std::map<ll, int>());
    std::map<ll, int> dp_max;
    vector<std::map<ll, int> > dp_min(3);
    auto base_0001 = [&](int Y, int M, int D) {
        // 0001-01-01 -> 0
        if (M <= 2) {
            Y--;
            M += 12;
        }
        return 365LL * Y + Y / 4 - Y / 100 + Y / 400
               + (153LL * (M - 3) + 2) / 5 + D - 307;
    };
    while (n--) {
        int y, M, d, h, m, s;
        scanf("%d-%d-%d %d:%d:%d", &y, &M, &d, &h, &m, &s);
        ll yes = base_0001(y, M, d - 1), tem = base_0001(y, M, d + 1), today = base_0001(y, M, d);
        if (h + 6 >= 24) {
            if (dp_max.contains(today)) dp_max[tem] = std::max(dp_max[today] + 1, dp_max[tem]);
            else dp_max[tem] = 1;
        }
        if (dp_max.contains(yes)) dp_max[today] = std::max(dp_max[today], dp_max[yes] + 1);
        else dp_max[today] = 1;
        if (h < 20) {
            if (dp_max.contains(yes - 1)) dp_max[yes] = std::max(dp_max[yes - 1] + 1, dp_max[yes]);
            else dp_max[yes] = 1;
        }

        if (h + 6 >= 24) {
            dp_min[2][tem] = std::min({dp_min[0][today], dp_min[1][today], dp_min[2][today]}) + 1;
        }
        dp_min[1][today] = std::min({dp_min[0][yes], dp_min[1][yes], dp_min[2][yes]}) + 1;
        if (h < 20) {
            dp_min[0][yes] = std::min({dp_min[0][yes - 1], dp_min[1][yes - 1], dp_min[2][yes - 1]}) + 1;
        }
    }
    int max = 0, min = INF;
    for (auto &[x,y]: dp_max) {
        max = std::max(y, max);
    }
    for (auto &m: dp_min) {
        int mx = 1;
        for (auto &[x,y]: m) {
            mx = std::max(y, mx);
        }
        min = std::min(mx, min);
    }
    cout << max << " " << min;
}

signed main() {
    init();
    int T = 1;
    if (more) cin >> T;
    while (T-- > 0) HuanF();
    return 0;
}

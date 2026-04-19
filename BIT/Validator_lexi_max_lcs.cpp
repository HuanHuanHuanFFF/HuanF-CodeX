#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PII = pair<int, int>;
using VI = vector<int>;
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());


struct BIT {
    vector<int> t;
    int n;

    BIT(int n): t(n + 1), n(n) {
    }

    int lowbit(int x) { return x & -x; }

    void set(int pos, int x) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            t[i] = std::max(t[i], x);
        }
    }

    int get(int pos) {
        int ans = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            ans = std::max(ans, t[i]);
        }
        return ans;
    }
};

bool is_subseq(const VI &seq, const VI &b) {
    int j = 0;
    for (int x: b) {
        if (j < (int) seq.size() && x == seq[j]) ++j;
    }
    return j == (int) seq.size();
}

// 暴力: 枚举 a 的所有子序列, 选长度最大、字典序最大的那个
VI solve_bruteforce(const VI &a, const VI &b) {
    int n = a.size();
    VI best;
    for (int mask = 0; mask < (1 << n); ++mask) {
        VI cur;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) cur.push_back(a[i]);
        }
        if (!is_subseq(cur, b)) continue;
        if (cur.size() > best.size() || (cur.size() == best.size() && cur > best)) {
            best = cur;
        }
    }
    return best;
}

// 这里放你的正解
VI solve_fast(const VI &a, const VI &b) {
    int n = a.size();
    vector<int> p(a), q(b), cp(p);
    std::map<int, int> pos;
    for (int i = 0; i < n; ++i) pos[q[i]] = i + 1;
    for (auto &x: p) x = pos[x];
    BIT dp(n);
    vector<int> suf(n + 1);
    for (int i = n; i > 0; --i) {
        suf[i] = dp.get(n + 1 - p[i - 1]) + 1;
        dp.set(n + 1 - p[i - 1], suf[i]);
    }
    std::map<int, vector<PII> > bucket;
    for (int i = 0; i < n; ++i) {
        bucket[suf[i + 1]].emplace_back(cp[i], i);
    }
    vector<int> ans;
    ans.reserve(bucket.rbegin()->first);
    int idx = -1, qpos = -1;
    for (auto &[x,y]: bucket | std::views::reverse) {
        std::ranges::sort(y, std::greater<>());
        for (auto &[f,s]: y) {
            if (s > idx && pos[f] > qpos) {
                idx = s;
                qpos = pos[f];
                ans.emplace_back(f);
                break;
            }
        }
    }
    return ans;
}

VI rand_perm(int n) {
    VI p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end(), rng);
    return p;
}

void print_vec(const VI &v) {
    for (int i = 0; i < (int) v.size(); ++i) {
        if (i) cerr << ' ';
        cerr << v[i];
    }
    cerr << '\n';
}

int main() {
    for (int tc = 1; ; ++tc) {
        // int n = uniform_int_distribution<int>(1, 6)(rng); // 暴力范围别开太大
        int n = 13;
        VI a = rand_perm(n);
        VI b = rand_perm(n);

        VI ans1 = solve_fast(a, b);
        VI ans2 = solve_bruteforce(a, b);

        if (ans1 != ans2) {
            cerr << "WA at test " << tc << '\n';
            cerr << "n = " << n << '\n';
            cerr << "a: ";
            print_vec(a);
            cerr << "b: ";
            print_vec(b);
            cerr << "fast: ";
            print_vec(ans1);
            cerr << "bruteforce: ";
            print_vec(ans2);
            return 0;
        }

        if (tc % 1000 == 0) {
            cerr << "Passed " << tc << " tests\n";
        }
    }
}

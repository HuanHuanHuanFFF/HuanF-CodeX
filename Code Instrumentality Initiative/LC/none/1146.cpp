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

class SnapshotArray {
    vector<vector<PII> > arr;
    int snap_cnt = 0;

public:
    SnapshotArray(int length) {
        arr.resize(length, vector<PII>({{-1, 0}}));
    }

    void set(int index, int val) {
        arr[index].emplace_back(snap_cnt, val);
    }

    int snap() {
        return snap_cnt++;
    }

    int get(int index, int snap_id) {
        int l = -1, r = arr[index].size();
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (arr[index][mid].first > snap_id)
                r = mid;
            else l = mid;
        }
        return arr[index][l].second;
    }
};

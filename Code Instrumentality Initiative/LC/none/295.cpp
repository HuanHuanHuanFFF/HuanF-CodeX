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

class MedianFinder {
    std::priority_queue<int, vector<int>, std::greater<int> > high;
    std::priority_queue<int> low;

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (high.size() != 0 && num > high.top()) {
            high.push(num);
        } else {
            low.push(num);
        }
        if (high.size() > low.size() + 1) {
            int t = high.top();
            high.pop();
            low.push(t);
        } else if (high.size() + 1 < low.size()) {
            int t = low.top();
            low.pop();
            high.push(t);
        }
    }

    double findMedian() {
        double ans;
        if (high.size() < low.size())
            ans = low.top();
        else if (high.size() == low.size())
            ans = (double) (high.top() + low.top()) / 2;
        else ans = high.top();
        return ans;
    }
};

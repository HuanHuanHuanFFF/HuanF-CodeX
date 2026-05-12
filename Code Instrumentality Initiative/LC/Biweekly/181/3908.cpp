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

class Solution {
public:
    bool validDigit(int n, int x) {
        bool a = false;
        while (n >= 10) {
            if (n % 10 == x) a = true;
            n /= 10;
        }
        if (n != x && a) return true;
        return false;
    }
};

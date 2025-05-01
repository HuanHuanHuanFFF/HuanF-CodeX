#include <bits/stdc++.h>
using namespace std;

template<int ALPHA = 26, bool UseMap = false>
struct Trie {
    struct Node {
        int link; // 失败指针（AC 用）
        bool isEnd; // 是否为单词结束
        int cnt; // 经过此节点的插入次数（前缀计数）
        array<int, ALPHA> nxt; // 数组版子节点
        map<char, int> mp; // map 版子节点

        Node() : link(0), isEnd(false), cnt(0) {
            nxt.fill(-1);
        }
    };

    vector<Node> t;

    Trie() {
        t.emplace_back();
    }

    // 将字符 ch 映射到 [0..ALPHA) 内
    int charId(char ch) const {
        if constexpr (ALPHA == 26) {
            // 只支持 'a'..'z'
            return ch - 'a';
        } else if constexpr (ALPHA == 52) {
            // 支持 'A'..'Z' -> 0..25； 'a'..'z' -> 26..51
            if (ch >= 'A' && ch <= 'Z') return ch - 'A';
            else return 26 + (ch - 'a');
        } else {
            // 其他情形，你可自行扩展
            return (unsigned char) ch % ALPHA;
        }
    }

    // 在节点 u 上取/建分支 ch，create=false 时不建
    int next(int u, char ch, bool create) {
        if constexpr (UseMap) {
            auto &mp = t[u].mp;
            auto it = mp.find(ch);
            if (it == mp.end()) {
                if (!create) return -1;
                int v = (int) t.size();
                mp[ch] = v;
                t.emplace_back();
                return v;
            }
            return it->second;
        } else {
            int c = charId(ch);
            if (t[u].nxt[c] == -1) {
                if (!create) return -1;
                t[u].nxt[c] = (int) t.size();
                t.emplace_back();
            }
            return t[u].nxt[c];
        }
    }

    // 插入一个字符串，并在每个经过节点累加前缀计数
    void insert(const string &s) {
        int u = 0;
        for (char ch: s) {
            u = next(u, ch, true);
            t[u].cnt++;
        }
        t[u].isEnd = true;
    }

    // 完整匹配：返回该单词出现的次数（0 或 1，可改为多次计数）
    int exactCount(const string &s) const {
        int u = 0;
        for (char ch: s) {
            u = next(u, ch, false);
            if (u < 0) return 0;
        }
        return t[u].isEnd ? 1 : 0;
    }

    // 以 prefix 为前缀的字符串数量
    int search(const string &prefix) const {
        int u = 0;
        for (char ch: prefix) {
            u = next(u, ch, false);
            if (u < 0) return 0;
        }
        return t[u].cnt;
    }

    // 可选：判断是否存在以 prefix 为前缀的单词
    bool startsWith(const string &prefix) const {
        return search(prefix) > 0;
    }
};

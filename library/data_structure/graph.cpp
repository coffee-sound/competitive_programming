#include <vector>

struct Edge {
    int to;     // 隣接頂点番号
    long long w;    // 重み
    Edge(int to, long long w) : to(to), w(w) {}
};

// using Graph = vector<vector<long long>>;
using Graph = vector<vector<Edge>>; // 重み付きグラフ
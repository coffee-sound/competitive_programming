#include <vector>
#include <queue>
using namespace std;

using Graph = vector<vector<long long>>;

/* topo_sort: グラフGをBFSを使ってトポロジカルソートする
    返り値: トポロジカルソートされた頂点をvectorで返す
    計算量: O(|E|+|V|)
*/

// トポロジカルソート
vector<int> topo_sort(const Graph &G) {
    vector<int> res;
    int N = (int)G.size();
    vector<int> in(N);      // 各頂点への入次数を記録
    for (int v = 0; v < N; ++v) {
        for (auto e : G[v]) {
            in[e]++;
        }
    }
    
    queue<int> que;
    for (int v = 0; v < N; ++v) {       // 入次数が0の点をキューに入れる
        if (in[v] == 0) que.push(v);
    }

    while (!que.empty()) {
        int v = que.front();        // 入次数が0の点を取りだす
        res.push_back(v);
        que.pop();

        for (auto e : G[v]) {
            in[e]--;    // 取り出した頂点を削除 -> つながっている辺の入次数が減る
            if (in[e] == 0) que.push(e);    // 入次数が0になったならキューに追加
        }
    }

    return res;
}
#include <vector>
using namespace std;

/* LCA(G, root): 木 G に対する根を root として 最小共通祖先(LCA:Lowest Common Ancestor) を求める
    query(u, v): u と v のLCAを求める O(logn)
    計算量: 前処理O(nlogn)
*/

class LCA {
    private:
    vector<vector<int>> parent;     // parent[k][v] := v の 2^k 先の親
    vector<int> dist;

    public:
    LCA(const vector<vector<int>> &G, int root = 0) { 
        init(G, root);
    }

    // initialize : ダブリングで 2^k 先の祖先を求める
    void init(const vector<vector<int>> &G, int root = 0) {
        int N = G.size();
        int K = 1;
        while ((1 << K) < N) ++K;       // ダブリングの上限を決める(n <= 2^K なる最小のK)
        parent.assign(K, vector<int>(N, -1));
        dist.assign(N, -1);
        dfs(G, root, -1, 0);
        
        // ダブリング
        for (int k = 0; k+1 < K; ++k) {
            for (int v = 0; v < N; ++v) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;      // 2^k 先が根なら 2^(k+1) 先も根
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }

    }

    // DFSですべての頂点の根からの距離と親を求める
    // d := 頂点 v の深さ
    void dfs(const vector<vector<int>> &G, int v, int p, int d) {
        parent[0][v] = p;       // 最初の一回は根なので親がいないのでその時は -1
        dist[v] = d;
        for (auto next_v : G[v]) {
            if (next_v == p) continue;      // 上方向(親)への遷移はしない
            dfs(G, next_v, v, d+1);     // d を 1 増やして子ノードへ
        }
    }    

    // u と v のLCAを求める
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);      // u の方が深いとする
        int N = parent.size();
        // LCA までの距離を同じにする O(logn)
        int d = dist[u] - dist[v];      // 深さの差
        for (int i = 0; i < N; ++i) {
            if ((d >> i) & 1) {     // d のビットを見る
                u = parent[i][u];       // ビットが立っている場合 2^i 分移動する
            }
        }

        // 二分探索
        if (u == v) return u;       // 揃えた結果 u,v が一致するならLCAは u(またはv)
        for (int i = N-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {     // u,v を2^i 先に移動させる (一致してればそれは共通祖先(最小とは限らない))
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];    // 最終的な u,v の一個上のノードがLCA
    }

    // 頂点 u,v 間の距離を求める
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2*dist[query(u, v)];
    }

    // 頂点 u,v を結ぶパス上に頂点 a が存在するか
    bool is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);   // パス上にあるとき u,a 間 + a,v 間が u,v 間の距離に等しい
    }
};

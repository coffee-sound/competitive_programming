#include <iostream>
#include <vector>
using namespace std;

// Union-Find
struct UnionFind {
    // par は各頂点 x の親
    vector<int> par, siz;

    // 初期化 すべてばらばらにする （x が親である場合は par[x] = -1）
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x;     // x が根の場合は x を返す
        else return par[x] = root(par[x]);      // x の親 par[x] を根に設定する（経路圧縮）
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(int x, int y) {
        // x, y をそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループの時は何もしない
        if (x == y) return false;

        // union by size (y 側のサイズが小さくなるようにする)
        if (siz[x] < siz[y]) swap(x, y);
        
        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};
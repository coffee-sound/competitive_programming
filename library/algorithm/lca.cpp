#include <vector>
using namespace std;

/* LCA(G, root): �� G ���Ф��뺬�� root �Ȥ��� �Ǿ���������(LCA:Lowest Common Ancestor) �����
    query(u, v): u �� v ��LCA����� O(logn)
    �׻���: ������O(nlogn)
*/

class LCA {
    private:
    vector<vector<int>> parent;     // parent[k][v] := v �� 2^k ��ο�
    vector<int> dist;

    public:
    LCA(const vector<vector<int>> &G, int root = 0) { 
        init(G, root);
    }

    // initialize : ���֥�󥰤� 2^k �����������
    void init(const vector<vector<int>> &G, int root = 0) {
        int N = G.size();
        int K = 1;
        while ((1 << K) < N) ++K;       // ���֥�󥰤ξ�¤����(n <= 2^K �ʤ�Ǿ���K)
        parent.assign(K, vector<int>(N, -1));
        dist.assign(N, -1);
        dfs(G, root, -1, 0);
        
        // ���֥��
        for (int k = 0; k+1 < K; ++k) {
            for (int v = 0; v < N; ++v) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;      // 2^k �褬���ʤ� 2^(k+1) ��⺬
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }

    }

    // DFS�Ǥ��٤Ƥ�ĺ���κ�����ε�Υ�ȿƤ����
    // d := ĺ�� v �ο���
    void dfs(const vector<vector<int>> &G, int v, int p, int d) {
        parent[0][v] = p;       // �ǽ�ΰ��Ϻ��ʤΤǿƤ����ʤ��ΤǤ��λ��� -1
        dist[v] = d;
        for (auto next_v : G[v]) {
            if (next_v == p) continue;      // ������(��)�ؤ����ܤϤ��ʤ�
            dfs(G, next_v, v, d+1);     // d �� 1 ���䤷�ƻҥΡ��ɤ�
        }
    }    

    // u �� v ��LCA�����
    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);      // u �����������Ȥ���
        int N = parent.size();
        // LCA �ޤǤε�Υ��Ʊ���ˤ��� O(logn)
        int d = dist[u] - dist[v];      // �����κ�
        for (int i = 0; i < N; ++i) {
            if ((d >> i) & 1) {     // d �ΥӥåȤ򸫤�
                u = parent[i][u];       // �ӥåȤ�Ω�äƤ����� 2^i ʬ��ư����
            }
        }

        // ��ʬõ��
        if (u == v) return u;       // ·������� u,v �����פ���ʤ�LCA�� u(�ޤ���v)
        for (int i = N-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {     // u,v ��2^i ��˰�ư������ (���פ��Ƥ�Ф���϶�������(�Ǿ��Ȥϸ¤�ʤ�))
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];    // �ǽ�Ū�� u,v �ΰ�ľ�ΥΡ��ɤ�LCA
    }

    // ĺ�� u,v �֤ε�Υ�����
    int get_dist(int u, int v) {
        return dist[u] + dist[v] - 2*dist[query(u, v)];
    }

    // ĺ�� u,v ���֥ѥ����ĺ�� a ��¸�ߤ��뤫
    bool is_on_path(int u, int v, int a) {
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);   // �ѥ���ˤ���Ȥ� u,a �� + a,v �֤� u,v �֤ε�Υ��������
    }
};

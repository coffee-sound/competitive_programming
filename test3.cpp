#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#define rep(i, a, b) for (int i = a; i < b; ++i)
using namespace std;

const int MOD = 1000000007;

const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }

int main() {
    int N; cin >> N;
    vector<pair<int, int>> cor(N);
    rep(i, 0, N) {
        int x, y; cin >> x >> y;
        cor[i] = {x, y};
    }

    sort(cor.begin(), cor.end());

    int ans = 0;
    rep(i, 0, N) {
        rep(j, 0, N) {
            if (cor[i].first < cor[j].first && cor[i].second < cor[j].second) {
                if ((binary_search(cor.begin(), cor.end(), make_pair(cor[i].first, cor[j].second))) && (binary_search(cor.begin(), cor.end(), make_pair(cor[j].first, cor[i].second)))) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
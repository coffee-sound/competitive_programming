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
    map<long long, long long> mpx, mpy;
    rep(i, 0, N) {
        long long x, y; cin >> x >> y;
        mpx[x]++;
        mpy[y]++;
    }

    long long ans = 0;
    for (auto x : mpx) {
        if (x.second == 1) continue;
        for (auto y : mpy) {
            if (y.second == 1) continue;
            ans += (x.second * (x.second - 1) / 2) * (y.second * (y.second - 1) / 2);
        }
    }

    cout << ans << endl;
    return 0;
}
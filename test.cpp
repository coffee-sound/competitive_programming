#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <queue>
#define rep(i, a, b) for (int i = a; i < b; ++i)
using namespace std;

const int MOD = 1000000007;

const long long INF = 1LL << 60;

template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } else return false; }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } else return false; }

int main() {
    string ss; getline(cin, ss);
    ss += ' ';
    vector<string> s;
    int cnt = 0;
    int index = 0;
    while (cnt < ss.size()) {
        if (ss[cnt] == ' ') {
            s.push_back(ss.substr(index, cnt-index));
            index += cnt-index+1;
        }
        cnt++;
    }
    int N; cin >> N;
    vector<string> ng(N);
    rep(i, 0, N) {
        ci
    }
}
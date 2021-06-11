#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using Graph = vector<vector<long long>>

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

const long long INF = 1LL << 60;
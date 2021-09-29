#include <iostream>
#include <vector>
using namespace std;

/* prime_factorize: 自然数 N を素因数分解する
    返り値: 素因数とその指数をそれぞれ組にしてvectorで返す
    計算量: O(√N)
    備考: 受け取るときはconst auto &res = prime_factorize(N) のように参照で受け取るとよい
*/

// Nの素因数分解
vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;       // N が a を因数に持たないときはスルー
        long long ex = 0;   // 指数

        // a で割れなくなるまで割る
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.emplace_back(a, ex);
    }

    // 最後に残った数が 1 でないならそれも N の因数となる
    if (N != 1) res.emplace_back(N, 1);
    return res;
}
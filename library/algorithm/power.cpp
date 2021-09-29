#include <iostream>
using namespace std;

const int MOD = 1000000007;

// x^n をO(logn)で計算
unsigned long long power(long long x, long long n) {
    if (n == 0) return 1;
    long long res = power(x, n / 2);
    if (n % 2 == 0) (res *= res) %= MOD;
    else {
        (res *= res) %= MOD;
        (res *= x) %= MOD;
    }
    return res;
}

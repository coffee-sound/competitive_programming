#include <vector>
#include <cmath>
using namespace std;

const int N = 100000;

vector<bool> isprime(N+1, true);

// エラトステネスの篩
// 関数呼び出しで，isprimeに格納
void sieve() {
    isprime[0] = false;
    isprime[1] = false;
    
    for (int i = 2; i * i <= N; ++i) {
        if (isprime[i]) {
            for (int j = 2; i * j <= N; ++j) {
                isprime[i * j] = false;
            }
        }
    }
}

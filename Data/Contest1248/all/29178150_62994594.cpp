#include <iostream>
#include <vector>

using namespace std;

using LL = long long;

const LL MOD = 1000000007LL;

LL fib(LL x) {
        if (x == 1) return 2;
        if (x == 2) return 4;
        LL a1 = 2;
        LL a2 = 4;
        for (LL i = 3; i <= x; i++) {
                LL tmp = (a1 + a2) % MOD;
                a1 = a2;
                a2 = tmp;
        }
        return a2;
}

int main() {
        LL N, M;
        cin >> N >> M;
        if (N < M) swap(N, M);
        LL ansN = fib(N);
        LL ansM = fib(M);
        cout << (ansN + ansM - 2) % MOD << endl;
        return 0;
}
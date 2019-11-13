#include <bits/stdc++.h>
using namespace std;

const long long P = 1000000007;

long long qpow(long long x, long long n){
    long long res = 1;
    x %= P;
    while (n){
        if (n & 1) res = res * x % P;
        x = x * x % P;
        n >>= 1; 
    }
    return res;
}

int main(){
    long long n, m;
    scanf("%I64d %I64d", &n, &m);
    long long ans = qpow(2, m) - 1;
    ans = qpow(ans, n);
    printf("%I64d\n", ans);
    return 0;
}
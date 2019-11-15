#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cmath>
#include<string>
#include<set>
#include<complex>
#include<cstdio>
#include<cstring>
#include<stack>
#include<iomanip>
#include<bitset>
#include<typeinfo>
#include<random>
#include<unordered_map>
#include<unordered_set>

using namespace std;

const long long mod = 1e9 + 7;

long long n, m;

long long quickpow(long long a, long long b, long long mod){
    long long res = a, ans = 1;
    while(b){
        if(b & 1) ans = ans * res % mod;
        res = res * res % mod;
        b >>= 1;
    }
    return ans;
}


int main(){
    scanf("%lld %lld", &n, &m);
    long long tmp = (quickpow(2, m, mod) - 1 + mod) % mod;
    printf("%lld\n", quickpow(tmp, n, mod));
    return 0;
}
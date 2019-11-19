#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
#include <string>
#include <set>
#include <complex>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <typeinfo>
#include <random>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int maxn = 1e5 + 10;
const long long mod = 1e9 + 7;

int n, m;
long long fib[maxn];

void init(){
    fib[0] = 1, fib[1] = 1;
    for(int i = 2; i <= maxn; i++){
        fib[i] = fib[i - 1] + fib[i - 2]% mod;
    }
}

int main(){
    init();
    scanf("%d %d", &n, &m);
    long long ans = (2LL * fib[n] % mod + 2LL * fib[m] - 2LL + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}
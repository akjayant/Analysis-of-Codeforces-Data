#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

const int mod = 1000000007;

long long exp(long long base, long long pwr) {
    long long res = 1;
    while (pwr) {
        if (pwr & 1) res = res*base % mod;
        base = base*base % mod;
        
        pwr >>= 1;
    }
    
    return res;
}

int main()
{
    if (fopen("data.in", "r"))
        freopen("data.in", "r", stdin);
    
    long long n,m;
    cin >> n >> m;
    
    int a = (exp(2,m)+mod-1)%mod;
    cout << exp(a,n) << endl;
    
}

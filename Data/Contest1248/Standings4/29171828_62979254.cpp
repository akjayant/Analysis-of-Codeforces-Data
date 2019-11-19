#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <set>
using namespace std;
#define ll long long
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
ll quickpow(ll a, ll b) {
	if (b < 0) return 0;
	ll ret = 1;
	a %= MOD;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ret % MOD;
}
int n;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
       cin>>n;
       ll a[2][2]={0};
       while(n--)
       {
          ll x;
           cin>>x;
           a[0][x%2]++;
       }
       cin>>n;
        while(n--)
       {
           ll x;
           cin>>x;
           a[1][x%2]++;
       }
       cout<<a[0][0]*a[1][0]+a[1][1]*a[0][1]<<endl;
    }
	return 0;
}

/*
4 5
2 3
6 1
*/

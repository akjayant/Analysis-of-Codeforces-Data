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
const ll N = 1e6+10 ;
   ll n;    ll sum = 0 ;
ll a[N];
void aa()
{
    cin >> n;

    for(ll i = 1 ; i<= n ; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
}
void aaa()
{

sort(a+1,a+1+n);

}
void aaaa()
{

ll cnt = 0 ;
    for(int i = 1 ; i <= n/2 ; i++)
    {
        cnt+=a[i];
    }
    cout << (sum-cnt)*(sum-cnt)+cnt*cnt <<endl;
}
int main()
{
 
    aa();
    aaa();
    aaaa();
    return 0;
}

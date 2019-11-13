#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18,mod=1e9+7,maxn=4e5+100;

int n,m,l,r,x,y,q,ans,res;

string s,t;

int a,b,c;
int binpow (int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return ((binpow (a, n-1)%mod) * (a%mod))%mod;
	else {
		int b = binpow (a, n/2)%mod;
		return ((b%mod) * (b%mod))%mod;
	}
}
main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    cout << binpow((binpow(2,m)-1+mod)%mod,n);


}

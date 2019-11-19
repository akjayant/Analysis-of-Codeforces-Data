#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define inf 0x3f3f3f3f
#define inff 0x3f3f3f3f3f3f3f3f
#define ll long long
#define ull unsigned long long
#define sscc ios::sync_with_stdio(false);cin.tie(0);
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
using namespace std;

const int mod=1e9+7;

const int N=1e6+5;

ll a[N],b[N],c[N];

int main()
{
	sscc;
	a[1]=2,a[2]=4;
	b[1]=0,b[2]=2;
	c[1]=0,c[2]=2;
	for(int i=3;i<=1e5;i++){
		a[i]=a[i-1]+a[i-2];
		a[i]%=mod;
		b[i]=b[i-1]+b[i-2];
		b[i]%=mod;
		c[i]=(c[i-1]+b[i])%mod;
	}
	ll n,m;
	cin>>n>>m;
//	cout<<a[n]<<" "<<c[m]<<endl;
	cout<<(a[n]+c[m])%mod<<endl;
	return 0;
}


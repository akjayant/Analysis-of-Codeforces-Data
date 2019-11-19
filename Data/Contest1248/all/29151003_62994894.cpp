#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int dir[8][2]={{1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{-1,0}};
#define pi acos(-1)
#define ls rt<<1
#define rs rt<<1|1
#define me0(s) memset(s,0,sizeof(s))
#define me1(s) memset(s,1,sizeof(s))
#define mef(s) memset(s,-1,sizeof(s))
#define meinf(s) memset(s,inf,sizeof(s))
#define llinf 1e18
const ll modd=1e9+7;
const int N=1e5;
ll a[N],c[N];
int main(int argc, char * argv[]) {
    ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	a[1]=2;
	a[2]=4;
	for(int i=3;i<=m;i++){
		a[i]=(a[i-1]+a[i-2])%modd;
	}
	c[1]=2;
	c[2]=2;
	for(int i=3;i<=n;i++){
		c[i]=(c[i-1]+c[i-2])%modd;
	}
	ll sum=a[m];
	for(int i=1;i<=n-1;i++){
		sum=(sum+c[i])%modd;
	}
	cout<<sum%modd<<endl;
	return 0;
}
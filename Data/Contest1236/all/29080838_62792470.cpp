#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 1LL<<60
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1010;
const LL mod=1e9+7;
LL qpow(LL a,LL b)
{
	LL res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1; 
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	LL ans=qpow(2,m);
	ans=qpow(ans-1,n);
	cout<<ans<<endl;
}
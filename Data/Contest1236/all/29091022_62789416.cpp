#include <bits/stdc++.h>
 
using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define int long long
const int N=1e6,INF=1e9,MOD=1e9+7;
int mas[N];
int st(int a,int k)
{
	if(k==1)return a;
	int q=st(a,k/2)%MOD;
	q=q%MOD*q%MOD;
	q%=MOD;

	if(k%2==1)q*=a;
	q%=MOD;
	return q;
}
 main()
{
	int n,m;
	cin>>n>>m;
	int ans=st(2,m);
	ans--;
	if(ans==-1)ans=MOD;
	ans=st(ans,n);
	ans%=MOD;
	cout<<ans;
}
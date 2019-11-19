#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 1e5+10;
ll p[N],q[N],a=0,n,m,b=0,ans,sum;
ll gg[N][5];
ll solve(int n,int m){
	gg[1][0]=gg[1][1]=gg[2][0]=gg[2][1]=gg[2][2]=gg[2][3]=1;	
	for(int i = 3;i <= max(n,m);++i){
		gg[i][0]=gg[i-1][2]%mod;
		gg[i][1]=(gg[i-1][0]+gg[i-1][2])%mod;
		gg[i][2]=(gg[i-1][1]+gg[i-1][3])%mod;
		gg[i][3]=gg[i-1][1]%mod;	
	}
	for(int i = 0; i < 4;++i)sum+=gg[m][i],ans+=gg[n][i];
	return (ans+sum-2)%mod;	
}
int main()
{
	ios::sync_with_stdio(0);

	cin>>n>>m;
	cout<<solve(n,m)<<endl; 
	
	return 0;
}
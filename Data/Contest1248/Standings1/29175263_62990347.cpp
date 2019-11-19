#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int n,m,t;
long long f[100001][2];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	t=max(n,m);
	f[1][1]=2;
	f[1][0]=0;
	for(int i=2;i<=t;i++)
	{
		f[i][0]=f[i-1][1],f[i][1]=f[i-1][0]+f[i-1][1];
		f[i][0]%=mod,f[i][1]%=mod;
	}
	cout<<(f[n][0]+f[n][1]+f[m][0]+f[m][1]-2)%mod<<endl;
	return 0;
}
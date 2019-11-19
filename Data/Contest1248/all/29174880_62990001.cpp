#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int MN=101010;
const int mod=1e9+7;
long long f[MN][2];

int main()
{
	int n,m;
	cin>>n>>m;
	f[1][0]=2;
	for(int i=2;i<=max(n,m);i++)
	{
		f[i][1]=f[i-1][0];
		f[i][0]=(f[i-1][1]+f[i-1][0])%mod;
	}
	cout<<(f[n][1]+f[n][0]+f[m][1]+f[m][0]-2)%mod<<endl;
}
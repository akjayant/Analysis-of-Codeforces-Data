#include<iostream>
using namespace std;
long long f[100001][2],n,m,p=1e9+7;
int main()
{
	cin>>n>>m;
	f[1][0]=2;
	f[1][1]=0;
	for (int i=2;i<=max(n,m);i++)
	{
		f[i][0]=(f[i-1][1]+f[i-1][0])%p;
		f[i][1]=f[i-1][0]%p;
	}
	cout<<(f[m][0]+f[m][1]+f[n][1]+f[n][0]-2)%p<<endl;
} 
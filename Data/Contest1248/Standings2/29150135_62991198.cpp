#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000000+7;
int f[100007][6];//1 3 column 2 4 row
int read()
{
	int x=0;char ch;ch=getchar();
	while(ch<'0' or ch>'9') ch=getchar();
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x;
}
void readArray(int a[],int n)
{
	for(int i=1;i<=n;i++) a[i]=read();
} 
signed main()
{
    int n,m,ans;
    n=read();m=read();
    f[1][1]=f[1][2]=1;
    for(int i=2;i<=max(n,m);i++)
    {
    	f[i][3]=f[i-1][1];
    	f[i][4]=f[i-1][2];
    	f[i][1]=f[i-1][2]+f[i-1][4];
    	f[i][2]=f[i-1][1]+f[i-1][3];
    	f[i][1]%=mod;
    	f[i][2]%=mod;
    	f[i][3]%=mod;
    	f[i][4]%=mod;
	}
	ans=-2;
	for(int i=1;i<=4;i++) ans+=f[m][i]+f[n][i],ans%=mod;
	cout<<(ans+mod)%mod;
}
/*

*/

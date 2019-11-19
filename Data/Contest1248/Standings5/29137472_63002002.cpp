#include<bits/stdc++.h>
#define rint register int
#define int long long
#define F(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define R(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
using namespace std;
typedef long long ll;
typedef long double ldb;
const int mod=1e9+7;
const int maxn=2e5+3;
int f[maxn][4];
inline int read()
{
	int x=0;
	bool f=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}
int Deal(int x)
{
	if(x==1) return 2;
	else
	{
		f[2][0]=f[2][1]=f[2][2]=f[2][3]=2;
		F(i,3,x)
		{
			f[i][0]=f[i-1][2];
			f[i][3]=f[i-1][1];
			f[i][1]=(f[i-1][2]+f[i-1][0])%mod;
			f[i][2]=(f[i-1][3]+f[i-1][1])%mod;
		}
	}
	return f[x][1]+f[x][3];
	memset(f,0,sizeof(f));
}
signed main()
{
	int n,m;
	cin>>n>>m;
	cout<<(Deal(n)+Deal(m)-2)%mod<<endl;
	return 0;
}

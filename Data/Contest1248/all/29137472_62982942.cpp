#include<bits/stdc++.h>
#define rint register int
#define F(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define R(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
using namespace std;
typedef long long ll;
typedef long double ldb;
const int maxn=1e5+3;
int cnt1,cnt2;
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
int main()
{
	int T=read();
	while(T--)
	{
	int n=read();
	cnt1=cnt2=0;
	F(i,1,n)
	{
		if(read()&1) cnt1++;
		else cnt2++;
	}
	int m=read();
	ll ans=0;
	F(i,1,m)
	{
		if(read()&1) ans+=cnt1;
		else ans+=cnt2;
	}
	cout<<ans<<endl;
	}
	return 0;
}

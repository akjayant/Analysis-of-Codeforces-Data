#include<bits/stdc++.h>
#define rint register int
#define int long long
#define F(i,a,b) for(register int i=(a),i##_end=(b);i<=i##_end;++i)
#define R(i,a,b) for(register int i=(a),i##_end=(b);i>=i##_end;--i)
using namespace std;
typedef long long ll;
typedef long double ldb;
const int maxn=1e5+3;
int a[maxn],ans=0;
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
signed main()
{
	int n=read();
	int cnt=0;
	F(i,1,n) a[i]=read(),cnt+=a[i];
	sort(a+1,a+n+1);
	if(n&1) for(rint i=n;i>=(n>>1)+1;--i) ans+=a[i];
	else for(rint i=n;i>=(n>>1)+1;--i) ans+=a[i];
	ans=ans*ans+(ll)(cnt-ans)*(cnt-ans);
	cout<<ans<<endl;
	return 0;
}

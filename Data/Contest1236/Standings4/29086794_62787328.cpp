//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int P=1e9+7;
int add(int a,int b)
{
	return (a+b>=P)?(a+b-P):(a+b);
}
int mul(int a,int b)
{
	return 1LL * a * b % P;
}
int fpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
int main()
{
	int n=read(),m=read();
	int ans=fpow(2,m);
	ans=add(ans,P-1);
	ans=fpow(ans,n);
	cout<<ans<<endl;
	return 0;
}

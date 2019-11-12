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
int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read();
		int ans=0;
		while(b>0 && c>1)
			ans+=3,--b,c-=2;
		while(a>0 && b>1)
			ans+=3,--a,b-=2;
		cout<<ans<<endl;
	}
	return 0;
}

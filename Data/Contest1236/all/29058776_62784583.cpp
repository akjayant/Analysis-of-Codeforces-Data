#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=(x<<1)+(x<<3)+(ch^48); ch=getchar(); }
	return x*f;
}
int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read(),ans=0;
		int t=min(b,c/2); ans+=t*3; b-=t;
		t=min(b/2,a); ans+=t*3;
		printf("%d\n",ans);
	}
	return 0;
}
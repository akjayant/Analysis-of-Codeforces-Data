#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int read()
{
	int x=0,y=1;char ch=getchar();
	while (ch>'9'||ch<'0'){
		if (ch=='-') y=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int a[1005],ans,n;
int main()
{
	int T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		ans=0;
		for (int i=n;i>=1;i--)
		if (ans+1<=a[i]) ans++;
		printf("%d\n",ans);
	}
}
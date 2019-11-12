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
int T,n,a[100];
char s[10005],t[10005],len;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		len=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i]!=t[i]) a[++len]=i;
			if (len>2) break;
		}
		if (len!=2)printf("NO\n");
		else{
			if(s[a[1]]==s[a[2]]&&t[a[1]]==t[a[2]]) printf("YES\n");
			else printf("NO\n");
		}
	}
}
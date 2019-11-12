#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

queue <int> fs,ft;
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while (ch>'9'||ch<'0'){
		if (ch=='-') y=-1;ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int T,n,a[30],m;
int x[1000],y[1000];
bool fff;
char s[105],t[105];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(a,0,sizeof a);
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		fff=0;
		for (int i=1;i<=n;i++)
		a[s[i]-'a']++,a[t[i]-'a']++;
		for (int i=0;i<26;i++)
		if (a[i]%2){
			printf("NO\n");
			fff=1;
			break;
		}
		if (fff) continue;
		m=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i]!=t[i])
			{
				for (int j=i+1;j<=n;j++)
				if (s[i]==s[j]){
					m++;
					x[m]=j;
					y[m]=i;
					swap(s[j],t[i]);
					break;
				}
			}
			if (s[i]!=t[i])
			{
				for (int j=i+1;j<=n;j++)
				if (t[i]==t[j])
				{
					m++;
					x[m]=i;
					y[m]=j;
					swap(s[i],t[j]);
					break;
				}
			}
			if (s[i]!=t[i])
			{
				for (int j=i+1;j<=n;j++)
				if (s[i]==t[j])
				{
					m++;
					x[m]=i+1;
					y[m]=j;
					swap(s[i+1],t[j]);
					m++;
					x[m]=i+1;
					y[m]=i;
					swap(s[i+1],t[i]);
					break;
				}
			}
		}
		if (s[n]!=t[n]){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%d\n",m);
		for (int i=1;i<=m;i++)
		printf("%d %d\n",x[i],y[i]);
	}
}
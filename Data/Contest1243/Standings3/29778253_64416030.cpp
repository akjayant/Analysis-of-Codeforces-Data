#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e4+10;
int T,n,s1[maxn],s2[maxn],num[30],cnt,l[maxn],r[maxn],nums[maxn],numt[maxn];
char s[maxn],t[maxn];
bool solve()
{
	cnt=0;
	for (int i=1;i<=26;i++) num[i]=0,nums[i]=0,numt[i]=0;
	for (int i=1;i<=n;i++) num[s[i]-'a'+1]++,nums[s[i]-'a'+1]++;
	for (int i=1;i<=n;i++) num[t[i]-'a'+1]++,numt[t[i]-'a'+1]++;
	for (int i=1;i<=26;i++) if (num[i]%2!=0) return 0;
	for (int i=1;i<=n;i++)
	if (s[i]!=t[i])
	{
		int lc=-1;
		for (int j=i+1;j<=n;j++) if (s[j]==s[i]) {lc=j; break;}
		if (lc!=-1)
		{
			cnt++; l[cnt]=lc; r[cnt]=i; swap(s[l[cnt]],t[r[cnt]]);
			continue;
		}
		for (int j=i+1;j<=n;j++) if (t[j]==t[i]) {lc=j; break;}
		if (lc!=-1)
		{
			cnt++; l[cnt]=i; r[cnt]=lc; swap(s[l[cnt]],t[r[cnt]]); 
			continue;
		}
		for (int j=i+1;j<=n;j++) if (s[j]==t[i]) {lc=j; break;}
		if (lc!=-1)
		{
			cnt++; l[cnt]=lc; r[cnt]=n; swap(s[l[cnt]],t[r[cnt]]); 
			cnt++; l[cnt]=i; r[cnt]=n; swap(s[l[cnt]],t[r[cnt]]);
			continue;
		}
		for (int j=i+1;j<=n;j++) if (t[j]==s[i]) {lc=j; break;}
		cnt++; l[cnt]=n; r[cnt]=lc; swap(s[l[cnt]],t[r[cnt]]);
		cnt++; l[cnt]=n; r[cnt]=i; swap(s[l[cnt]],t[r[cnt]]);
	}
return 1;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,s+1,t+1); 
		if (!solve()) printf("No\n");
		else 
		{
			printf("Yes\n%d\n",cnt);
			for (int i=1;i<=cnt;i++) printf("%d %d\n",l[i],r[i]);
		}
	}
return 0;
}
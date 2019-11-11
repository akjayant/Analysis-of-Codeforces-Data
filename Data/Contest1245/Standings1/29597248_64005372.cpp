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
const int N=1e5+7,mo=1e9+7;
inline int fk(int x) { return x>=mo ? x-mo : x; }
int n,f[N][2],ans=1;
char s[N];
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	f[1][0]=1;
	for(int i=2;i<=n;i++)
		f[i][0]=fk(f[i-1][0]+f[i-1][1]),
		f[i][1]=f[i-1][0];
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='w'||s[i]=='m') { printf("0\n"); return 0; }
		if(s[i]=='u'||s[i]=='n')
		{
			int l=i;
			while(s[l+1]==s[i]) l++;
			ans=1ll*ans*fk(f[l-i+1][0]+f[l-i+1][1])%mo;
			i=l;
		}
	}
	printf("%d\n",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define next Next
#define gc getchar
#define int long long
const int mod=1e9+7;
const int N=1e6+5;
int n,f[N];
char s[N],ss[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='m'||s[i]=='w'){puts("0");return 0;}
	f[1]=1;f[2]=2;
	for(int i=3;i<=n;i++)f[i]=(f[i-1]+f[i-2])%mod;
	int ans=1;
	for(int i=1,j=1;i<=n;i=j+1)
	{
		j=i;
		while(j+1<=n&&s[j+1]==s[j])j++;
		if(s[i]=='u'||s[i]=='n')
		{
			ans=ans*f[j-i+1]%mod;
		}
	}
	cout<<ans;
}
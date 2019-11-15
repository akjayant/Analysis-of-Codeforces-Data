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
void inc(int &a,int b)
{
	a=add(a,b);
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
const int MAXN=1e5+10;
char buf[MAXN];
int n,f[MAXN];
int main()
{
	scanf("%s",buf);
	n=strlen(buf);
	f[0]=f[1]=1;
	for(int i=2;i<=n;++i)
		f[i]=add(f[i-1],f[i-2]);
	int ans=1;
	for(int i=0,j;i<n;++i)
	{
		if(buf[i]=='m' || buf[i]=='w')
			ans=0;
		j=i;
		while(j+1<n && buf[j+1]==buf[i])
			++j;
		if(buf[i]=='n' || buf[i]=='u')
			ans=mul(ans,f[j-i+1]);
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define inf 0x7f7f7f7f
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int t;
int a,b,c,d,k;
int an1,an2;
int main()
{
	t=read();
	while(t--)
	{
		a=read(); b=read(); c=read(); d=read(); k=read();
		int ans=0;
		if(a%c==0) { ans=a/c; an1=a/c; }
		else { ans=a/c+1; an1=a/c+1; }
		if(b%d==0) { ans+=b/d; an2=b/d; }
		else { ans+=b/d+1; an2=b/d+1; }
		if(an1+an2<=k) printf("%d %d\n",an1,an2);
		else printf("-1\n");
	}
	return 0;
}

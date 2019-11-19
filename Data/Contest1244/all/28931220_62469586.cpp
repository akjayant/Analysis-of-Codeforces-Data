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
int n,t;
int a[1005];
int mx,mn;
int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		a[i]=getchar()-'0';
		int numb=0;
		mx=0; mn=n+1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) 
			{ numb++; mx=max(mx,i); mn=min(mn,i); }
		}
		if(numb==0) printf("%d\n",n+numb);
		else printf("%d\n",2*(max(n-mx,mn-1)+mx-mn+1));
	}
	return 0;
}

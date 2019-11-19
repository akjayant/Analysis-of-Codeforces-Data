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
int n,a[100005];
ll k;
ll pre[100005];
ll las[100005];
bool com(int x,int y)
{ return x<y; }
ll check2(int x,int y)
{
	int l1=x,r1=x+y;
	ll sum=0;
	int l=1,r=n;
	int pos;
	while(l<r)
	{
		if(r-l<=1) 
		{
		    if(a[r]<=l1) pos=r; 
			else pos=l;
			break;
		} 
		int mid=(l+r)>>1;
		if(a[mid]<=l1) l=mid;
		else r=mid;
	}
	sum=sum+1LL*pos*l1-pre[pos];
	l=1,r=n;
	while(l<r)
	{
		if(r-l<=1) 
		{
		    if(a[r]<=r1) pos=r; 
			else pos=l;
			break;
		} 
		int mid=(l+r)>>1;
		if(a[mid]<=r1) l=mid;
		else r=mid;
	}
	sum=sum+las[pos+1]-1LL*(n-pos)*r1;
	return sum;
}
bool check1(int x)
{
	int l=a[1],r=a[n];
	int l1,r1;
	ll lasl=check2(l,x),lasr=check2(r,x);
	while(l<r)
	{
		if(lasl<=k||lasr<=k) return 1;
		if(r-l<=2) 
		{
		    if(check2(l,x)<=k) return 1;
		    else if(check2(r,x)<=k) return 1;
		    else if(check2((l+r)>>1,x)<=k) return 1; 
			return 0;
		}
		l1=l+(r-l)/3; r1=r-(r-l)/3;
		ll p=check2(l1,x),q=check2(r1,x);
		if(p<q) { r=r1; lasr=q; }
		else  { l=l1; lasl=p; }
//		if(p<lasl) { l=l1; lasl=p; }
//		if(q<lasr) { r=r1; lasr=q; }
	}
}
int main()
{
	n=read(); cin>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,com);
	int l=0,r=a[n]-a[1];
	for(int i=1;i<=n;i++)
	pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;i--)
	las[i]=las[i+1]+a[i];
	while(l<=r)
	{
		if(l==r)
		{
			printf("%d",l);
			break;
		}
		else if(r-l==1) 
		{
		    if(check1(l)) printf("%d",l);
		    else printf("%d",r);
		    break;
		}
		int mid=(r+l)>>1;
		if(check1(mid)) r=mid;
		else l=mid;
	}
	return 0;
}

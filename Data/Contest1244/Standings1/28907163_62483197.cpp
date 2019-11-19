#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
int n; ll k;
int a[maxn];
int l,r;
int ans;
int num[maxn],val[maxn];
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int f=1;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) f=0;
	if(f)
	{
		printf("0");
		return 0;
	}
    sort(a+1,a+1+n);
    l=1; 
    int cnt=0;
    while(true)
    {
    	if(l>n) break;
		int nn=1; 
		while(l<n&&a[l+1]==a[l]) l++,nn++;
		cnt++;
		val[cnt]=a[l];
		num[cnt]=nn;
	    l++;
	}
	l=1,r=cnt;
	ans=val[cnt]-val[1];
	ll tmp;
	ll cst;
	while(true)
	{
		if(k<=0) break;
		if(l==r) break;
		if(num[l]<num[r])
		{
		    tmp=(ll)val[l+1]-(ll)val[l];
			cst=(ll)tmp*(ll)num[l];
			if(k>=cst)
			{
			    ans-=val[l+1]-val[l];
			    k-=cst;
			    num[l+1]+=num[l];
			}	
			else
			{
				tmp=k/(ll)num[l];
				ans-=tmp;
				k=0;
			}
			l++;
		}
		else
		{
			tmp=(ll)val[r]-(ll)val[r-1];
			cst=(ll)tmp*(ll)num[r];
			if(k>=cst)
			{
				ans-=val[r]-val[r-1];
				k-=cst;
				num[r-1]+=num[r];
			}
			else
			{
				tmp=k/(ll)num[r];
				ans-=tmp;
				k=0;
			}
			r--;
		}
	}
	printf("%d",ans);
	return 0;
}
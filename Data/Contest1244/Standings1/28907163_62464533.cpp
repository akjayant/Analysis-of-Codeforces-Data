#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long 
int a,b,c,d,k;
int main()
{
	int t; scanf("%d",&t);
	int ans,bns;
	while(t--)
	{
		bns=ans=0;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if(a%c==0) ans+=a/c;
		else ans+=a/c+1;
		if(b%d==0) bns+=b/d;
		else bns+=b/d+1;
		if(ans+bns>k) printf("-1\n");
		else
		printf("%d %d\n",ans,bns);
	}
	return 0;
}
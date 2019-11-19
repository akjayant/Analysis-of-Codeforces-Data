#include<stdio.h>
#include<iostream>
using namespace std;

#define MOD 1000000007

long long s[100005],h[100005];

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	s[1]=h[1]=2;
	s[2]=h[2]=4;
	for(i=3;i<=n;i++)s[i]=(s[i-1]+s[i-2])%MOD;
	for(i=3;i<=m;i++)h[i]=(h[i-1]+h[i-2])%MOD;
	printf("%lld",(s[n]+h[m]-2)%MOD);
}
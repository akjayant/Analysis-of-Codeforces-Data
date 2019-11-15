/*
Author: WangXP
Date:
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inc(i,n) for (int i=0;i<n;i++)
#define icc(i,n) for (int i=1;i<=n;i++)
#define rep(i,a,b) for (int i=a;i<b;i++)
#define rpp(i,a,b) for (int i=a;i<=b;i++)
#define dec(i,n) for (int i=n-1;i>=0;i--)
#define dcc(i,n) for (int i=n;i;i--)
ll rd(){
	ll x=0,f=1;char c=getchar();
	while (!isdigit(c) && c!='-') c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N=500010;

char a[100010],b[100010];
int df[100010];

int main(){
	int k=rd();
	while (k--){
		int n=rd();
		scanf("%s%s",a,b);
		int dc=0;
		inc(i,n) if (a[i]!=b[i]) df[dc++]=i;
		if (dc==1 || dc>2){
			puts("No");
			continue;
		}
		if (dc==0 || dc==2 && a[df[0]]==a[df[1]] && b[df[0]]==b[df[1]]){
			puts("Yes");
			continue;
		}
		puts("No");
	}	
	return 0;
}

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
const ll p=1e9+7;
char s[N];
ll fib[N];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	fib[1]=fib[0]=1;
	for (int i=2;i<=200000;i++) fib[i]=(fib[i-1]+fib[i-2])%p;
	ll ans=1;
	for(int i=0;i<n;){
		if (s[i]=='m' || s[i]=='w') return puts("0"),0;
		if (s[i]!='n' && s[i]!='u') {i++; continue;}
		int j;
		for (j=i+1;j<n && s[j]==s[j-1];j++);
		ans*=fib[j-i];
		ans%=p;
		i=j;
	}
	cout<<ans<<'\n';
	return 0;
}

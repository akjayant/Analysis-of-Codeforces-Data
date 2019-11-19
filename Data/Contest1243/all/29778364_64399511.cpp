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

int a[N];

int main(){
	ll n0,t=0,n; cin>>n0; n=n0;
	if (n==1) return puts("1"),0;
	for (ll i=2;i*i<=n;i++) if (n%i==0){
		t=__gcd(t,i);
		while (n%i==0) n/=i;
	}
	if (n>1) t=__gcd(t,n);
	cout<<t<<'\n';
	return 0;
}

#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll a[maxn];

inline ll read(){
    ll x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

int main(){
	ll n=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	ll t1=0,t2=0;
	for(ll i=1;i<=n/2;i++) t1+=a[i];
	for(ll i=n/2+1;i<=n;i++) t2+=a[i];
	cout<<t1*t1+t2*t2<<endl;
	return 0;
}

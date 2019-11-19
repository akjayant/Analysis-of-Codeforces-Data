#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

inline ll gcd(ll x,ll y){return x%y==0?y:gcd(y,x%y);}

ll n,ans;

int main(){
	n=read();ans=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)ans=gcd(ans,gcd(i,n/i));
	}cout<<ans;
	return 0;
}

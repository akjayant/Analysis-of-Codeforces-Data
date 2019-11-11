#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll read(){
	char c=getchar();bool flag=0;ll x=0;
	while(c<'0'||c>'9'){if(c=='-')flag=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return flag?-x:x;
}
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b); 
}
int main(){
	ll T=read();
	while(T--){
		ll a=read(),b=read();
		if(gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	} 
}


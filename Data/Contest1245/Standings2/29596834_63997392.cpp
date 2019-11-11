#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}
	return x*f;
}
LL T,n,m;
int main(){
	T=Read();
	while(T--){
		n=Read(); m=Read();
		if(std::__gcd(n,m)==1) puts("Finite");
		else puts("Infinite");
	}
}
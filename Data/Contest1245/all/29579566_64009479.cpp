#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=1e6+5;
const int mod=1000000007;
const double inf=100000000;
int T;
int a,b;
inline int gcd(int a,int b){
	if(!b) return a;
	else return gcd(b,a%b);
}
int main(){
	T=read();
	while(T--){
		a=read();b=read();
		if(gcd(a,b)!=1) puts("Infinite");
		else puts("Finite");
	}
	return 0;
}
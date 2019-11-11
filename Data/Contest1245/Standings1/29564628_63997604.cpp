#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define inf 0x7fffffff
#define ll long long

using namespace std;

inline int read(){
    int x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}

inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int t=read();
	while(t--){
		int a=read(),b=read();
		if(gcd(a,b)==1) printf("Finite\n");
		else printf("Infinite\n");
	} 
	return 0;
}

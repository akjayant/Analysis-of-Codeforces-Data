#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	int cas=read();
	while(cas--){
		int a=read(),b=read();
		if(__gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}
	return 0;
}


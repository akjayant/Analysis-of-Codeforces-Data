#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;

int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}

int k,m,n;
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}

int main(){
	int t=read();
	while(t--){
		n=read();m=read();
		if(gcd(n,m)!=1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}
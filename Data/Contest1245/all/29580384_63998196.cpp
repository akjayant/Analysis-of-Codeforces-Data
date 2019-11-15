#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e5+10;
int T,a,b;

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int gcd(int a,int b){return b==0?a:gcd(b,a%b);}

int main(){
	T=read();
	while(T--){
		a=read(),b=read();
		if(gcd(a,b)>1) printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define MAXN 100010
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
int n,m;

void read(int &X){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	X=x*f;
}

int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}

int main(){
	read(n),read(m);
	int temp=qpow(2,m);
	temp=(temp-1+mod)%mod;
	int ans=qpow(temp,n);
	cout<<ans<<endl;
	return 0;
}

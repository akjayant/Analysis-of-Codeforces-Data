#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define ll long long

using namespace std;

void TaskA(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,e;
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
		int x=(a-1)/c+1,y=(b-1)/d+1;

		if(x+y>e)puts("-1");
		else printf("%d %d\n",e-y,y);
	}
}

void TaskB(){
	int t;
	scanf("%d",&t);
	char c[1005];
	while(t--){
		int N;
		int op=-1;
		int ed=-1;
		scanf("%d %s",&N,c+1);
		for(int i=1;i<=N;i++)
			if(c[i]=='1')ed=i;
		for(int i=N;i>=1;i--)
			if(c[i]=='1')op=i;
		if(ed==-1){
			printf("%d\n",N);
			continue;
		}
		printf("%d\n",max(op-1,N-ed)*2+(ed-op+1)*2);
	}
}

void extended(long long a,long long b,long long& x,long long& y) {
	if(!b) {
		x=1,y=0;
		return ;
	}
	extended(b,a%b,y,x);
	y-=a/b*x;
}
void TaskC(){
	ll a,b,c,d,g,base=0;
	ll e=0,x=0,y=0,o=0,tmp=0,fo=0;
	ll cnt=0;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	g=__gcd(d,c);
	if(b%g){ puts("-1");return;}
	b/=g,c/=g,d/=g;
	if(d!=1) {
		e=b/(c*d);
		b-=e*c*d,base=e*d;
		extended(c,d,x,y);
		x=(x%d+d)%d;
		o=x*c/d;
		tmp=b/d;
		fo=(b%d)*x+base;
		tmp-=(b%d)*o;
	} else {
		fo=b/c;
		tmp=b%c;
	}

	if(tmp<0) {
		cnt=(-tmp)/c;
		tmp+=(cnt+1)*c;
		fo-=(cnt+1)*d;
	}
	cnt=tmp/c;
	tmp-=cnt*c;
	fo+=cnt*d;
	if(fo<0||fo+tmp>a) puts("-1");
	else printf("%lld %lld %lld\n",fo,tmp,a-fo-tmp);
}

void TaskD(){
	
}
void TaskE(){
	
}


void TaskG(){
	
}
signed main(){

	#ifndef ONLINE_JUDGE
       	freopen("input.txt","r",stdin);
    #endif
	
	//TaskA();
	//TaskB();
	TaskC();
	//TaskD();
	//TaskE();
	//TaskF();
    //TaskG();
}
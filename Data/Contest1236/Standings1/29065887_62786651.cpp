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
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
int T,a,b,c,a1,b1,c1;

void read(int &X){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	X=x*f;
}

int main(){
	read(T);
	while(T--){
		int ans1=0,ans2=0;
		read(a),read(b),read(c);
		a1=a,b1=b,c1=c;
		ans1=min(a,b/2);
		b-=ans1*2;ans1*=3;
		ans1+=min(b,c/2)*3;
		ans2=min(b1,c1/2);
		b1-=ans2;ans2*=3;
		ans2+=min(a1,b1/2)*3;
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}

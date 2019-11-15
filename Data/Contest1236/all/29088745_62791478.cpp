#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

const int MOD=1e9+7;
int ans,n,m,k;

int mult(int x,int y){
	int ret=1,mt=x;
	while(y){
		if(y&1) ret=(1ll*ret*mt%MOD);
		mt=(1ll*mt*mt)%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	k=mult(2,m);
	k=(k-1+MOD)%MOD;
	ans=mult(k,n);
	printf("%d\n",ans);
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <stdlib.h>
using namespace std;
typedef long long int lld;
typedef long double ld;
int gcds(lld a,lld b){
	lld tmp;
	while(b!=0){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
int main(void){
	lld n,p,d,w;
	cin >> n >> p >> w >> d;
	lld now = gcds(d,w);
	if(p%now){
		printf("-1");
		return 0;
	}	
	lld tt = max((lld)0,(lld)((p-n*d)/(w-d))),tmp = 0;
	lld err=0;
	while(true){
		lld now = tt*w;
		if(now>p) break;
		if(tmp>10*w) break;
		if((p-now)%d==0)
		{
			lld now2 = (p-now)/d;
			if(tt+now2<=n){
				printf("%lld %lld %lld",tt,now2,n-tt-now2);
				err++;
				break;
			}
		}	
		tt++;
		tmp++;
	}
	if(err==0) printf("-1");
	return 0;
}
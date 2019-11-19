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

int main(void){
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,k,err = 0;
		cin >> a >> b >> c >> d >> k;
		for(int e=1;e<=k;e++){
			int rr = k-e;
			if(c*e>=a&&d*rr>=b){
				printf("%d %d\n",e,rr);
				err++;
				break;
			}
		}
		if(err==0)printf("-1\n");
	}
	return 0;
}
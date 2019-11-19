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
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> ev,od;
		for(int e=0;e<n;e++){
			int r;
			scanf("%d",&r);
			if(r%2==0) ev.push_back(r);
			else od.push_back(r);
		}
		lld ans = 0;
		int m;
		scanf("%d",&m);
		for(int e=0;e<m;e++){
			int k;
			scanf("%d",&k);
			if(k%2==0) ans += (lld)(ev.size());
			else ans += (lld)(od.size());
		}
		printf("%lld\n",ans);
	}
	return 0;
}
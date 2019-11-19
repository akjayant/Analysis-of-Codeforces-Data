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
		int n;
		string a;
		cin >> n >> a;
		int ans = (int)a.size();
		for(int e=0;e<a.size();e++){
			if(a[e]=='1'){
				ans = max(ans,(e+1)*2);
			}
		}
		for(int e=(int)a.size()-1;e>=0;e--){
			if(a[e]=='1'){
				int sz = (int)(a.size());
				ans = max(ans,(sz-e)*2);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
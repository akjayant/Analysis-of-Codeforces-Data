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
int arr[111111];
int main(void){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++) scanf("%d",&arr[e]);
	if(n==1){
		printf("%lld",(lld)arr[0]*(lld)arr[0]);
		return 0;
	}
	lld tot = 0;
	for(int e=0;e<n;e++) tot += (lld)(arr[e]);
	sort(arr,arr+n);
	if(n%2==0){
		lld f = 0;
		for(int e=0;e<n/2;e++) f += (lld)(arr[e]);
		lld s = tot - f;
		printf("%lld",f*f+s*s);
	}else{
		lld f = 0;
		for(int e=0;e<n/2;e++) f += (lld)(arr[e]);
		lld s = tot - f;
		lld ans1 = f*f + s*s;
		f = 0;
		for(int e=0;e<=(n/2);e++) f+= (lld)(arr[e]);
		s = tot -f;
		ans1 = max(ans1,f*f+s*s);
		printf("%lld",ans1);
	}
	return 0;
}
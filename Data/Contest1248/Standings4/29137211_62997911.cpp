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
const lld mod = 1e9 + 7;
lld dp[111111];
int main(void){
	dp[1] = 1;
	dp[2] = 2;
	for(int e=3;e<111111;e++) dp[e] = (dp[e-1]+dp[e-2])%mod;
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m){
		int tmp = n;
		n = m;
		m = tmp;
	}
	if(n==1&&m==1){
		printf("2");
		return 0;
	}
	printf("%lld",(((dp[m]+dp[n]-1+mod)*2)%mod));
	return 0;
}
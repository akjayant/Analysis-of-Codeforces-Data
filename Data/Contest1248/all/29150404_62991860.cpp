#include <string.h>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stdlib.h>    
#include <time.h> 
#include <stack>
#include <queue>
#include <set>
 
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
 
#define ll long long
#define clr(x) memset(x,0,sizeof(x))
#define _clr(x) memset(x,-1,sizeof(x))
#define fr(i,a,b) for(int i = a; i < b; ++i)
#define frr(i,a,b) for(int i = a; i > b; --i)
#define pb push_back
#define sf scanf
 
#define pf printf
#define mp make_pair
 
using namespace std;
const int N = 410000;
const int mod = 1000000007;

int a[1000000];

ll dp[N][2];

ll ft(int m) {
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][0] = 2;
	dp[1][1] = 2;
	for(int i = 2 ; i < m; ++i) {
		dp[i][0] = (dp[i-1][1] + dp[i-2][1])%mod;
		dp[i][1] = (dp[i-1][0] + dp[i-2][0])%mod;
	}

	return (dp[m-1][0] + dp[m-1][1] - 2+mod)%mod;
}

int main(){
	int n,m;
	cin>>n>>m;
	
	ll tot1 = ft(n)+2;
	ll tot2 = ft(m);
	cout<<(tot1+tot2)%mod<<endl;
}


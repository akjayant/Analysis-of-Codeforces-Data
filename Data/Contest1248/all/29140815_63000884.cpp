#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define mp make_pair

ll solve(int n, int k) 
{ 
    ll dp[n + 1]; 
    for(int i= 0; i<=n;i++)
    	dp[i]=0;
    ll mod = 1000000007; 
  	int i=2;
    dp[1] = k; 
  
    int same = 0, diff = k; 
  
    while(i<=n) 
    { 
        same = diff; 
  
        diff = dp[i-1] * (k-1); 
        diff = diff % mod; 
  
        dp[i] = (same + diff) % mod;
        i++; 
    } 
  
    return dp[n]; 
} 
int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll ans =0 ;
	ans = solve(n,2) + solve(m,2) -2;
	ans=ans%1000000007;
	printf("%lld\n",ans );

	return 0;
}
//  A STUPID MONSTER :(
#include <bits/stdc++.h>
#define SPEED ios::sync_with_stdio(false); cin.tie(0)
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define dbg(x) cout<<#x<<": "<<x<<endl
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mo 1000000007
#define inf 1e18
#define eps 0.0000000001
#define stp setprecision(20)
#define all(v) v.begin(),v.end()
#define endl '\n'
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

#define N  int(2e5)+10
ll dp[N];
int main()
{    SPEED;

   ll n,m;cin>>n>>m;
    ll vl1=0;
     dp[1]=2;
     dp[2] = 4;
     dp[3] = 6;ll nn = max(n,m) ,mini = min(n,m);  
     loop(i,4,nn+1){
     	 dp[i] = 2*dp[i-1]-dp[i-3] ;dp[i] =  (dp[i]%mo+mo)%mo;
		  
	 }
	 cout<<(dp[n]+dp[m]-2+mo)%mo<<endl;
	 
	    
}



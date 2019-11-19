#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define pdd pair<double , double>
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define mod  1000000007
#define N    100005
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcountll
#define PI acos(-1)
// #define mid  (l + r )/2
#define s3   1.73205080757
const int inf = (int)1e18+10 ;
const int MAX= 200005;
vec b;
int n;
int c[3][N];
vec v[N];
int dp[N][3][3];
int ans1[N];
void dfs(int x , int p){
	 b.pb(x);
	 for(auto y : v[x]){
	 	  if(y == p) continue;
	 	  dfs(y , x);
	 }
}
void f(int x , int y , int z){
	  for(int i = n-1 ; i >= 0 ; i--){
	  	   if((n - i - 1) %3 == 0) ans1[b[i]] = x;
	  	   else if((n - i - 1)%3 == 1) ans1[b[i]] = y;
	  	   else ans1[b[i]] = z; 
	  }
}
signed main(){
  fast;
  
  int x , root , y;
  cin >> n;
  for(int i = 0 ; i < 3 ; i++){
  	   for(int j = 1 ; j  <= n ; j++)
  	   	   cin >> c[i][j];
  }
  for(int i = 1 ; i < n ; i++){
  	cin >> x >> y;
  	v[x].pb(y);
  	v[y].pb(x);
  }
  for(int i = 1 ; i <= n ; i++){
  	    if(v[i].size() >= 3){
  	    	cout << -1 << endl;
  	    	return 0;
  	    }
  	    if(v[i].size() == 1){
  	    	   root = i;
  	    }
  }
  dfs(root , -1);
  dp[1][0][1] = c[0][b[1]] + c[1][b[0]];
  dp[1][1][0] = c[1][b[1]] + c[0][b[0]];
  dp[1][0][2] = c[0][b[1]] + c[2][b[0]];
  dp[1][2][0] = c[2][b[1]] + c[0][b[0]];
  dp[1][1][2] = c[1][b[1]] + c[2][b[0]];
  dp[1][2][1] = c[2][b[1]] + c[1][b[0]];

  for(int i = 2 ; i < n  ; i++){
        dp[i][0][1] = dp[i-1][1][2] + c[0][b[i]];
        dp[i][1][0] = dp[i-1][0][2] + c[1][b[i]];
        dp[i][0][2] = dp[i-1][2][1] + c[0][b[i]];
        dp[i][2][0] = dp[i-1][0][1] + c[2][b[i]];
        dp[i][2][1] = dp[i-1][1][0] + c[2][b[i]];
        dp[i][1][2] = dp[i-1][2][0] + c[1][b[i]];

  }
  int ans = inf;
        ans = min(ans , dp[n-1][0][1]); 
        ans = min(ans , dp[n-1][1][0]);
        ans = min(ans , dp[n-1][0][2]); 
        ans = min(ans , dp[n-1][2][0]);
        ans = min(ans , dp[n-1][2][1]); 
        ans = min(ans ,dp[n-1][1][2]);
        cout << ans << endl;
        if(ans == dp[n-1][0][1]){
        	f(1 , 2 , 3);
        }
        else if(ans == dp[n-1][1][0]){
        	f(2 , 1 , 3);
        }
        else if(ans == dp[n-1][0][2]){
        	f(1 , 3, 2);
        }
        else if(ans == dp[n-1][2][0]){
        	f(3 , 1 , 2);
        }
        else if(ans == dp[n-1][2][1]){
        	f(3 , 2 , 1);
        }
        else{
        	f(2 , 3 , 1);
        }
        for(int i = 1 ; i <= n ; i++)
        	cout << ans1[i] << " ";
        cout <<endl;



 // check for n=1 edge case 
}

/*input
2
3
1 1 1
RPS
3
3 0 0
RPS
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 101;
int dp[N][N][N];
int where[N][N][N];

void solve(){
	int n,a,b,c;cin >> n >> a >> b >> c;
  	string s;cin >> s;
  	vector<char> ans(n,'F');
  	int wins = 0;
  	REP(i,n){
  		if(s[i] == 'S' and a){
  			a--;
  			wins++;
  			ans[i] = 'R';
  		}
  		if(s[i] == 'R' and b){
  			b--;
  			wins++;
  			ans[i] = 'P';
  		}
  		if(s[i] == 'P' and c){
  			c--;
  			wins++;
  			ans[i] = 'S';
  		}
  	}
  	if(wins < (n+1)/2){
  		cout << "NO\n";
  		return;
  	}
  	REP(i,n){
  		if(ans[i] == 'F'){
  			if(a){
  				ans[i] = 'R';a--;
  			}
  			else if(b){
  				ans[i] = 'P';b--;
  			}
  			else {
  				ans[i] = 'S';c--;
  			}

  		}
  	}
  	cout << "YES\n";
  	print(ans);
  	/*REP(i,N){
  		REP(j,N){
  			REP(k,N)dp[i][j][k] = 0;
  		}
  	}
  	RE(tot,n){
  		REP(j,n+1){
  			REP(k,n+1){
  				int i = tot-(j+k);
  				if(i < 0)continue;
  				dp[i][j][k] = 0;
  				if(tot == 0){
  					if(i and dp[i][j][k] < dp[i-1][j][k]){
  						dp[i][j][k] = dp[i-1][j][k];
  						where[i][j][k] = 0;
  					}
  					if(j and dp[i][j][k] < dp[i][j-1][k]){
  						dp[i][j][k] = dp[i][j-1][k];
  						where[i][j][k] = 1;
  					}
  					if(k and dp[i][j][k] < dp[i][j][k-1]){
  						dp[i][j][k] = dp[i][j][k-1];
  						where[i][j][k] = 2;
  					}
  				}
  				else{
  					if(i and dp[i][j][k] < dp[i-1][j][k]+(s[n-tot] == 'S')){
  						dp[i][j][k] = dp[i-1][j][k]+(s[n-tot] == 'S');
  						where[i][j][k] = 0;
  					}
  					if(j and dp[i][j][k] < dp[i][j-1][k]+(s[n-tot] == 'R')){
  						dp[i][j][k] = dp[i][j-1][k]+(s[n-tot] == 'R');
  						where[i][j][k] = 1;
  					}
  					if(k and dp[i][j][k] < dp[i][j][k-1]+(s[n-tot] == 'P')){
  						dp[i][j][k] = dp[i][j][k-1]+(s[n-tot] == 'P');
  						where[i][j][k] = 2;
  					}
  				}
  			}
  		}
  	}
  	//cout << dp[0][0][1] << endl;
  	if(dp[a][b][c] >= (n+1)/2){
  		cout << "YES\n";
  		int cura = a;
  		int curb = b;
  		int curc = c;
  		while(n--){
  			if(where[cura][curb][curc] == 0){cout << 'R';cura--;}
  			else if(where[cura][curb][curc] == 1){cout << 'P';curb--;}
  			else {cout << "S";curc--;}
  		}
  	}
  	else{
  		cout << "NO";
  	}
  	cout << endl;*/
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}
/*input
3
3 4 5
1 0 5
5 3 2
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
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
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

bool vis[N][N][N];
queue< pair< pair<int,int>, int> > q;
int n;

void solve(){
  	//cin >> n;
  	int a,b,c;cin >> a >> b >> c;
  	while(!q.empty())q.pop();
  	REP(i,N){
  		REP(j,N){
  			REP(k,N)vis[i][j][k] = 0;
  		}
  	}
  	q.push({{a,b},c});
  	int ans = 0;
  	vis[a][b][c] = 1;
  	int suma = a+b+c;
  	while(!q.empty()){
  		int a1 = q.front().f.f;
  		int b1 = q.front().f.s;
  		int c1 = q.front().s;
  		q.pop();
  		ans = max(ans,suma-(a1+b1+c1));
  		if(a1 > 0 and b1 > 1){
  			if(vis[a1-1][b1-2][c1]){

  			}
  			else{
  				vis[a1-1][b1-2][c1] = 1;
  				q.push({{a1-1,b1-2},c1});
  			}
  		}
  		if(b1 > 0 and c1 > 1){
  			if(vis[a1][b1-1][c1-2]){

  			}
  			else{
  				vis[a1][b1-1][c1-2] = 1;
  				q.push({{a1,b1-1},c1-2});
  			}
  		}
  	}
  	cout << ans << "\n";
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
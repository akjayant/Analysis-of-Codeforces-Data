#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
#define N 1000009
#define M 255
#define INF 1000000007
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%lld%lld",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d ",x);
#define pf2(x,y) printf("%d %d\n",x,y);
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z);
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define tr(x) cout<<x<< endl;
#define tr2(x,y) cout<<x<<" "<<y<< endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(x,y,z,a) cout<<x<<" "<<y<<" "<<z<<  " " << a << " " << endl;
#define sz(x) ((ll) (x).size())

ll power(ll a, ll b){
  if(b==0){
    return 1;
  }
  ll c = power(a, b/2);
  c = c*c%MOD;
  if(b%2){
    return (c*a)%MOD;
  }
  else{
    return c;
  }
}

int main(){
  ll i,j,k,x = 0,y,idx1, idx2,t,i1,m,z = 0,x1,x2, y1, y2,n;
  cin >> x >> y;
  z = (power(2, y)-1+MOD)%MOD;
  ll ans = power(z, x);
  tr(ans);
}
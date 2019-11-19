#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
#define N 2009
#define M 32
#define INF 10000000000007
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf(x) printf("%d",x);
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

vector<ll> v;

int main(){
  ll i,j,k,x,y,m,q,idx1, idx2,t,f,i1,j1,z,n,d;
  cin >> n;
  ll ans = n;
  x  = 0;
  for(i = 2; i*i<=n; i++){
    x = 0;
    while(n%i==0){
      x = 1;
      n = n/i;
    }
    if(x){v.pb(i);}
  }
  if(n>1 && n<ans){v.pb(n);}

  // for(auto p:v){
    // tr2("---",p);
  // }
  if(n==ans){
    tr(ans);
  }
  else if(sz(v)==1){
    tr(v[0]);
  }
  else{
    tr(1);
  }
  // tr(ans);
  


  
  return 0;
}
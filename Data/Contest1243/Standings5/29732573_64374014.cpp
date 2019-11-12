#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;
#define N 1000009
#define M 29
#define INF 1000000007
#define MOD 1000000007
#define MOD1 1000000009
#define MOD2 1000000007
typedef long long int ll;
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
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

int a[1009];
int solve(){
  int i,j,k,n,m,x,y;
  sd(n);
  fill(a, a+1009, 0);
  for(i = 0; i<n; i++){
    sd(x);
    for(j = x; j>0; j--){
      a[j]++;
    }
  }
  int ans = 0;
  for(i = 0; i<1009; i++){
    if(a[i]>=i){
      ans = max(ans, i);
    }
  }
  return ans;
}

int  main(){
  int i,j,c,x = 0,y,idx1, idx2,t,i1,m,z = 0,n,k;
  sd(t);
  while(t--){
    x = solve();
    tr(x);
  }
}
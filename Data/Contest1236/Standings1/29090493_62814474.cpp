  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  #include <bits/stdc++.h>
  
  using namespace __gnu_pbds;
  using namespace std;
  #define N 1000009
  #define M 320
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


ll cnt = 0;
vector<int> row[N], col[N];
vector<pair<int,int>> v;
set<int> rowc, colc;
void solve(int x, int y, int type){
  // tr3(x,y,type);
  int i,j,k, val1, val2, x1, y1;
  // int x = 1, y = 1;
  if(type==1){
    auto it  = colc.lower_bound(y);
    if(*it==y){++it;}
    i = lower_bound(row[x].begin(), row[x].end(), y)-row[x].begin();
    // tr3("--", *it, row[x][i]);
    y1 = min(*it, row[x][i])-1;
    rowc.insert(x);
    cnt += 1ll*(y1-y);
    if(y!=y1)solve(x, y1, 2);

  }
  else if(type==2){
    auto it  = rowc.lower_bound(x);
    if(*it==x){it++;}
    i = lower_bound(col[y].begin(), col[y].end(), x)-col[y].begin();
    // tr3("--", *it, col[y][i]);
    x1 = min(*it, col[y][i])-1;
    colc.insert(y);
    cnt += 1ll*(x1-x);
    if(x!=x1)solve(x1, y, 3);
  }
  else if(type==3){
    auto it  = colc.lower_bound(y);

    i = lower_bound(row[x].begin(), row[x].end(), y)-row[x].begin();
    i--;
    it--;
    y1 = max(*it, row[x][i])+1;
    rowc.insert(x);
    cnt += 1ll*(y-y1);
    if(y!=y1)solve(x, y1, 4);
  }
  else{
    auto it  = rowc.lower_bound(x);
    i = lower_bound(col[y].begin(), col[y].end(), x)-col[y].begin();
    i--;
    it--;
    x1 = max(*it, col[y][i])+1;
    colc.insert(y);
    cnt += 1ll*(x-x1);
    if(x!=x1)solve(x1, y, 1);
  }

}

  int main(){
    ll i,j,k,x = 0,y,idx1, idx2,t,i1,m,z = 0,x1,x2, y1, y2,n;
    cin >> n >> m >> k;
    for(i = 0; i<k; i++){
      cin >> x >> y;
      v.pb(mp(x,y));
      row[x].pb(y);
      col[y].pb(x);
    }
    for(i = 1; i<=n; i++){
      row[i].pb(0);
      row[i].pb(m+1);
      sort(row[i].begin(), row[i].end());
    }
    for(i = 1; i<=m; i++){
       col[i].pb(0);
       col[i].pb(n+1);
      sort( col[i].begin(), col[i].end());
    }
    rowc.insert(0);
    rowc.insert(n+1);
    colc.insert(0);
    colc.insert(m+1);
    solve(1,1,1);
    ll ans1 = cnt +1ll*k + 1ll*1;
    cnt = 0;
    solve(1,1,2);
    ll ans2 = cnt+1ll*k+1ll*1;
    if(ans1==1ll*n*m || ans2==1ll*n*m){
      tr("Yes");
    }
    else{
      tr("No");
    }



  }
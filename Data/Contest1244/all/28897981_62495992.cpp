#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }
#define ALL(x) (x).begin(), (x).end()
LL POW(LL a,LL p,LL M){ if(!p) return 1LL;LL T = POW(a,p/2,M);T = T*T%M; if(p&1) T=T*(a%M)%M; return T; }
LL SQRT(LL a) { LL b = (LL)sqrtl(((double)a)+0.5); while(b*b<a) ++b; while(b*b>a) --b; return (b*b==a)?b:-1; }
//endl
//<------------------------edits---------------------------------------------->
const LL MOD = 1e9+7;//998244353
// #define LOCAL LDD
#define int LL
const int N = 1e5;
int cst[N+2][3];
int cx[N+2];
vector<vector<int>> t(N+2);
int lef;
LL dfs(int nd,int pr,int up1,int up2){
  LL f = cst[nd][up1];
  set<int> vv;vv.insert(up1);vv.insert(up2);
  int ex;
  for(int j=0;j<3;j++) if(vv.find(j)==vv.end()) ex = j;
  int tx = 0;
  for(int i:t[nd]){
    if(i==pr) continue;
    tx++;
    f += dfs(i,nd,ex,up1);
  }
  if(tx==0) lef = nd;
  return f;
}
void print(int nd,int pr,int up1,int up2){
  cx[nd] = up1;
  set<int> vv;vv.insert(up1);vv.insert(up2);
  int ex;
  for(int j=0;j<3;j++) if(vv.find(j)==vv.end()) ex = j;
  for(int i:t[nd]){
    if(i==pr) continue;
    print(i,nd,ex,up1);
  }
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
#endif
  int n;cin >> n;
  for(int j=0;j<3;j++) for(int i=1;i<=n;i++) cin >> cst[i][j];
  for(int i=1;i<n;i++){
    int x,y;cin >> x >> y;
    t[x].push_back(y);t[y].push_back(x);
  }
  dfs(1,0,0,1);
  int flef = lef;
  LL f = LONG_LONG_MAX;
  pair<int,int> ff;
  for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i==j) continue; else{
    LL g = dfs(flef,0,i,j);
    if(g<f){
      f = g;
      ff = {i,j};
    }
  }
  int cft = 0;
  for(int i=1;i<=n;i++){
    if(t[i].size()==1) cft++;
    else if(t[i].size()>2){
      cout << -1 << endl;
      return 0;
    }
  }
  if(cft!=2){
    cout << -1 << endl;
    return 0;
  }
  cout << f << endl;
  print(flef,0,ff.first,ff.second);
  for(int i=1;i<=n;i++) cout << cx[i]+1 << " ";
  cout << endl;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
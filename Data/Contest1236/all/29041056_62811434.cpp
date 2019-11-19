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
// #define int LL
set<pair<int,int>> sf;
map<int,set<int>> xvis,yvis;
int l1,l2,r1,r2,d;
void sv(){
  if(l1>l2||r1>r2){
    assert(sf.size()==0);
    cout << "Yes\n";
    exit(0);
  }
  if(sf.find({l1,r1})!=sf.end()){
    for(int i=l1;i<=l2;i++) for(int j=r1;j<=r2;j++){
      if(sf.find({i,j})==sf.end()) {cout << "No\n";exit(0);}
      sf.erase({i,j});
      xvis[i].erase(j);
      yvis[j].erase(i);
    }
    cout << "Yes\n";
    exit(0);
  }
  if(d==0){
    if(xvis[l1].size()){
      int ss = *(xvis[l1].begin());
      for(int i=l1;i<=l2;i++) for(int j=ss;j<=r2;j++){
        if(sf.find({i,j})==sf.end()) {cout << "No\n";exit(0);}
        sf.erase({i,j});
        xvis[i].erase(j);
        yvis[j].erase(i);
      }
      r2 = ss-1;
    }
    d = 1;
    return ;   
  }else if(d==1){
    if(yvis[r2].size()){
      int ss = *(yvis[r2].begin());
      for(int i=ss;i<=l2;i++) for(int j=r1;j<=r2;j++){
        if(sf.find({i,j})==sf.end()) {cout << "No\n";exit(0);}
        sf.erase({i,j});
        xvis[i].erase(j);
        yvis[j].erase(i);
      }
      l2 = ss-1;
    }
    d = 2;
    return ;
  }else if(d==2){
    if(xvis[l2].size()){
      int ss = *(xvis[l2].rbegin());
      for(int i=l1+1;i<=l2;i++) for(int j=r1;j<=ss;j++){
        if(sf.find({i,j})==sf.end()) {cout << "No\n";exit(0);}
        sf.erase({i,j});
        xvis[i].erase(j);
        yvis[j].erase(i);
      }
      r1 = ss+1;
    }
    d = 3;
    return ;
  }else{
    if(yvis[r1].size()){
      int ss = *(yvis[r1].rbegin());
      for(int i=l1+1;i<=ss;i++) for(int j=r1;j<r2;j++){
        if(sf.find({i,j})==sf.end()) {cout << "No\n";exit(0);}
        sf.erase({i,j});
        xvis[i].erase(j);
        yvis[j].erase(i);
      }
      l1 = ss+1;
      r1++;
      l2--;r2--;
    }else{
      l1++;r1++;l2--;r2--;
    }
    d = 0;
    return ;
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
#endif
  int n,m,k;cin >> n >> m >> k;
  while(k--){
    int a,b;cin >> a >> b;
    sf.insert({a,b});
    xvis[a].insert(b);
    yvis[b].insert(a);
  }
  l1 = 1;r1 = 1;l2 = n;r2 = m;d = 0;
  while(1) sv();
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);cout << fixed;
#ifdef LOCAL
  freopen("input.txt", "rt", stdin);
#endif
  
  int n;cin >> n;
  string s;cin >> s;
  int f = 0;
  pair<int,int> tt;
  for(int i=0;i<n;i++) for(int j=i;j<n;j++){
    int h = 0;
    string t = s;
    swap(t[i],t[j]);
    vector<int> op,cl;
    for(int k=0;k<n;k++){
      if(t[k]=='(') op.push_back(k);
      else if(t[k]==')'){
        if(op.size()) op.pop_back();
        else cl.push_back(k);
      }
    }
    if(op.size()==cl.size()){
      int st = 0;int ed = n-1;
      if(op.size()){
        if(op[0]>cl.back()){
          h = 1;
          st = cl.back()+1;
          ed = op[0]-1;
        }else st = -1;
      }
      if(st!=-1){
        int tt = 0;
        for(int k=st;k<=ed;k++){
          if(t[k]=='(') tt++;
          else tt--;
          if(tt==0) h++;
        }
      }
    }
    if(h>=f){
      f = h;
      tt.first = i+1;
      tt.second = j+1;
    }
  }
  cout << f << endl;
  cout << tt.first << " " << tt.second << endl;
  
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
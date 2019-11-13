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
  
  int k;cin >> k;
  while(k--){
    int n;cin >> n;
    string s,t;cin >> s >> t;
    vector<pair<int,int>> mm;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]) continue;
        int x = -1;
        for(int j=i+1;j<n;j++) if(t[i]==t[j]){
          x = j;
          break;
        }
        if(x==-1){
          for(int xx=i+1;xx<n;xx++) if(s[xx]==t[i]){
            mm.push_back({xx+1,xx+1});
            swap(t[xx],s[xx]);
            x = xx;
            break;
          }
        }
        if(x==-1) break;
        mm.push_back({i+1,x+1});
        t[x] = s[i];
        s[i] = t[i];
      }
    if(s==t){
      cout << "Yes\n";
      cout << mm.size() << endl;
      for(auto it:mm) cout << it.first << " " << it.second << endl;
    }else cout << "No\n";
  }
  
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
  return 0;
}
#include <bits/stdc++.h>
#define rep(i,s,e) for(int i = s; i < e; i++)
#define test(t) int t; cin >> t; while(t--) 
#define iterate(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef set<int> si;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(6) << fixed;
  ll n;
  cin >> n;
  ll v = (ll) sqrt(n);
  for(ll i = 2; i <= v; ++i) {
    if(n % i == 0) {
      while(n % i == 0) {
        n/=i;
      }
      if(n == 1) {
        cout << i << endl;
        return 0;
      } else {
        cout << 1 << endl;
        return 0;
      }
    }
  }
  cout << n << endl;
  return 0;
}


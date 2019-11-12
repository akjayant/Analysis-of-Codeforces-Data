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
  int t,a,b,c;
  cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    int m = min(b,c/2);
    b -= m;
    m += min(a,b/2);
    cout << 3*m << endl;
  }
  return 0;
}


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
  int n;
  cin >> n;
  vector<int> arr[n];
  rep(i,0,n) {
    rep(j,0,n) {
      if(i%2) {
        arr[j].push_back(n*n-n*i-(n-j)+1);
      } else {
        arr[j].push_back(n*n-n*i-j);
      }
    }
  }
  rep(i,0,n) {
    rep(j,0,n) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}


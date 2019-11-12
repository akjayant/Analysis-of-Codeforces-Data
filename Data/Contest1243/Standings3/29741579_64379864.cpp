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
  int k;
  cin >> k;
  while(k--) {
    int n;
    string a,b;
    cin >> n >> a >> b;
    vector<int> diffs;
    rep(i,0,n) {
      if(a[i] != b[i]) {
        diffs.push_back(i);
      }
    }
    if(diffs.size() == 0) {
      cout << "Yes" << endl;
    } else if(diffs.size() == 2) {
      if(a[diffs[0]] == a[diffs[1]] && b[diffs[0]] == b[diffs[1]]) cout << "Yes" << endl;
      else cout << "No" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}


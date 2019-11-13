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
    unordered_map<char,int> count;
    rep(i,0,n) {
      if(a[i] != b[i]) {
        count[a[i]]++;
        count[b[i]]++;
        diffs.push_back(i);
      }
    }
    if(diffs.size() == 0) {
      cout << "Yes" << endl;
      cout << 0 << endl;
      continue;
    }
    bool err = false;
    for(auto it = count.begin(); it != count.end(); ++it) {
      if(it -> second % 2 != 0) {
        cout << "No" << endl;
        err = true;
        break;
      }
    }
    if(err) continue;
    vector<pair<int,int>> sol;
    for(int i = 0; i < diffs.size(); ++i) {
      int mindex = diffs[i];
      if(a[mindex] == b[mindex]) continue;
      for(int j = i+1; j < diffs.size(); ++j) {
        int tindex = diffs[j];
        if(a[mindex] == a[tindex]) {
          sol.push_back({tindex,mindex});
          b[mindex] = b[mindex] ^ a[tindex];
          a[tindex] = b[mindex] ^ a[tindex];
          b[mindex] = b[mindex] ^ a[tindex];
          break;
        }
        if(a[mindex] == b[tindex]) {
          sol.push_back({tindex,tindex});
          a[tindex] = b[tindex] ^ a[tindex];
          b[tindex] = b[tindex] ^ a[tindex];
          a[tindex] = b[tindex] ^ a[tindex];

          sol.push_back({tindex,mindex});
          b[mindex] = b[mindex] ^ a[tindex];
          a[tindex] = b[mindex] ^ a[tindex];
          b[mindex] = b[mindex] ^ a[tindex];

          break;
        }
      }
   }
    for(int i = 0; i < n; ++i) {
      if(a[i] != b[i]) {
        err = true;
        break;
      }
    }
    if(err) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      cout << sol.size() << endl;
      rep(i,0,sol.size()) cout << sol[i].first+1 << ' ' << sol[i].second+1 << endl;
    }
  }
  return 0;
}


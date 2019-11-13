#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; cin >> n;
  int a, b, c; cin >> a >> b >> c;
  string s; cin >> s;
  vector<int> brr[26];
  int p1 = 'R' - 'A';
  int p2 = 'P' - 'A';
  int p3 = 'S' - 'A';
  for(int i = 0; i < s.size(); ++i) {
    brr[s[i] - 'A'].emplace_back(i);
  }
  string ans;
  for(int i = 0; i < n; ++i) {
    ans += '*';
  }
  int cnt = 0;
  while(brr[p1].size()) {
    if(b == 0) break;
    ans[brr[p1].back()] = 'P';
    brr[p1].pop_back(); 
    --b;
    ++cnt;
  }
  while(brr[p2].size()) {
    if(c == 0) break;
    ans[brr[p2].back()] = 'S';
    brr[p2].pop_back();
    --c;
    ++cnt;
  }
  while(brr[p3].size()) {
    if(a == 0) break;
    ans[brr[p3].back()] = 'R';
    brr[p3].pop_back();
    --a;
    ++cnt;
  }
  int half = ceil(n / 2.0);
  if(cnt >= half) {
    for(int i = 0; i < ans.size(); ++i) {
      if(ans[i] == '*') {
        if(a > 0) ans[i] = 'R', --a;
        else if(b > 0) ans[i] = 'P', --b;
        else if(c > 0) ans[i] = 'S', --c;
      }
    }
    assert(a == 0 && b == 0 && c == 0);
    cout << "YES\n" << ans << "\n";
  } else {
    cout << "NO\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int T;
  cin >> T;
  while(T--){
    solve();
  }
}
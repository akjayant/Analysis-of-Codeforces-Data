#include <bits/stdc++.h>
using namespace std;

int k,n,i,j,cnt[30],done;
string s,t;
vector <pair<int,int>> ans;
int main() {
  cin >> k;
  while(k--) {
    memset(cnt, 0, sizeof cnt);
    done = 0;
    ans.clear();
    cin >> n;
    cin >> s;
    cin >> t;
    for(i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
      cnt[t[i] - 'a']++;
    }
    for(i = 0; i < 26; i++) {
      if(cnt[i] % 2 == 1) {
        done = 1;
        break;
      }
    }
    if(done) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    for(i = 0; i < n - 1; i++) {
      if(s[i] != t[i]) {
        done = 0;
        for(j = i + 1; j < n; j++) {
          if(s[j] == s[i]) {
            ans.push_back({j+1, i+1});
            swap(s[j],t[i]);
            done = 1;
            break;
          }
        }
        if(done) continue;
        for(j = i + 1; j < n; j++) {
          if(t[j] == s[i]) {
            ans.push_back({i+2, j+1});
            ans.push_back({i+2, i+1});
            swap(s[i+1], t[j]);
            swap(s[i+1], t[i]);
            break;
          }
        }
      }
    }
    cout << ans.size() << "\n";
    for(auto x : ans) {
      cout << x.first << " " << x.second << "\n";
    }
  }
  return 0;
}
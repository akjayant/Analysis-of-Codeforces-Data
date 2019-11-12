#include <bits/stdc++.h>
using namespace std;

int main(){
  int k; cin >> k;
  while(k --){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, int> m;
    for(int i = 0; i < n; i ++){
      m[s[i]] ++;
      m[t[i]] ++;
    }
    bool f = true;
    for(auto x: m){
      if(x.second % 2 == 1)
        f = false;
    }
    if(!f){
      cout << "No" << endl;
      continue;
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i ++){
      if(s[i] != t[i]){
        bool f = false;
        for(int j = i+1; j < n; j ++){
          if(s[j] == s[i]){
            ans.push_back({j, i});
            swap(s[j], t[i]);
            f = true;
            break;
          }
        }
        if(f) continue;
        for(int j = i + 1; j < n; j ++){
          if(t[j] == s[i]){
            ans.push_back({n-1, j});
            swap(s[n-1], t[j]);
            ans.push_back({n-1, i});
            swap(s[n-1], t[i]);
            break;
          }
        }
      }
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(auto x: ans)
      cout << x.first+1 << " " << x.second+1 << endl;
  }
}

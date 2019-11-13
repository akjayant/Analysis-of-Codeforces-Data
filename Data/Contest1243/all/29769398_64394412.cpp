#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  while(k--){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> vec1(26, 0);
    for(auto a : s1)vec1[a - 'a']++;
    for(auto a : s2)vec1[a - 'a']++;
    bool flag = false;
    for(auto a : vec1){
      if(a&1){
        cout << "No\n";
        flag = true;
        break;
      }
    }
    if(flag)continue;
    cout << "Yes\n";
    int m =0;
    vector<pair<int,int>> vec;
    for(int x =0; x<n; x++){

      if(s1[x] == s2[x])continue;
      for(int y = x+1; y<n; y++){
        if(s2[x] == s2[y])
        {
          char d = s1[x];
          s1[x] = s2[y];
          s2[y] = d;
          vec.push_back({x+1, y+1});
          break;
        }
      }
      if(s1[x] != s2[x]){
        for(int y = x+1; y<n; y++){
          if(s1[y] == s2[x]){
            char d = s2[n-1];
            s2[n-1] = s1[y];
            s1[y] = d;
            vec.push_back({y+1, n});
            s2[n-1] = s1[x];
            vec.push_back({1+x, n});
            break;
          }
        }
      }
    }
    cout << vec.size() << "\n";
    for(auto a : vec){
      cout << a.first << " " << a.second << "\n";
    }
  }
  return 0;
}

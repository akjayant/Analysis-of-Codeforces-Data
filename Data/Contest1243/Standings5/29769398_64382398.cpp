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
    vector<int> vec;
    for(int x =0; x<n; x++)if(s1[x] != s2[x])vec.push_back(x);
    if(vec.size() == 2 && s1[vec[0]] == s1[vec[1]] && s2[vec[0]] == s2[vec[1]])
      cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}

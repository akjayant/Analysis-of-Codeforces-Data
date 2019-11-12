#include <bits/stdc++.h>
using namespace std;

int main(){
  int k; cin >> k;
  while(k --){
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> v;
    for(int i = 0; i < n; i ++){
      if(s[i] != t[i])
        v.push_back(i);
    }
    if(v.size() == 2 && s[v[0]] == s[v[1]] && t[v[0]] == t[v[1]])
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
}

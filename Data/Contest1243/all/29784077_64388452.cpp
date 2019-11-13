#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

ll mod = 1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k;
  cin >> k;

  while(k--){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    string ans = "Yes";
    vector<pii> ret;
    for(int i = 0;i < n;i++){
      if(s[i] != t[i]){
        bool check = false;
        for(int j = i+1;j < n;j++){
          if(s[j] == s[i]){
            check = true;
            swap(t[i],s[j]);
            ret.push_back(make_pair(j+1,i+1));
            break;
          }
          if(t[j] == s[i]){
            check = true;
            swap(t[j],s[j]);
            swap(t[i],s[j]);
            ret.push_back(make_pair(j+1,j+1));
            ret.push_back(make_pair(j+1,i+1));
            break;
          }
        }
        if(!check){
          ans = "No";
          break;
        }
      }
    }
    cout << ans << endl;
    if(ans == "Yes"){
      cout << ret.size() << endl;
      for(int i = 0;i < ret.size();i++){
        cout << ret[i].first << " " << ret[i].second << endl;
      }
    }
  }
}

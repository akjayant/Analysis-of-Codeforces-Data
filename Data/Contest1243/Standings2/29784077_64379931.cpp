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
    int cnt = 0;
    vi p;
    for(int i = 0;i < n;i++){
      if(s[i] != t[i]){
        cnt++;
        p.push_back(i);
      }
    }
    if(cnt == 0)cout << "Yes" << endl;
    else if(cnt == 2){
      if(s[p[0]] == s[p[1]] && t[p[1]] == t[p[0]])cout << "Yes" << endl;
      else cout << "No" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}

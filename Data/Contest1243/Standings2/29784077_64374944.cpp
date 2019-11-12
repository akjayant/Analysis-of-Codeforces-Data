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
    vi a(n);
    for(int i = 0;i < n;i++){
      cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int ret = 0;
    while(ret < n){
      if(a[ret] <= ret)break;
      ret++;
    }
    cout << ret << endl;
  }
}

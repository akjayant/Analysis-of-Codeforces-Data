#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define double long double
#define fo(i, n)    for(int i = 0; i < n; i ++)
#define foe(i, n)   for(int i = 0; i <= n; i ++)
#define fo1(i, n)   for(int i = 1; i < n; i ++)
#define fo1e(i, n)  for(int i = 1; i <= n; i ++)
using namespace std;

int32_t main(){
  int n, k;
  cin >> n >> k;
  vector<int> ar;
  map<int, int> cnt;
  fo(i, n){
    int x; cin >> x;
    if(cnt[x] == 0)
      ar.pb(x);
    cnt[x] ++;
  }
  sort(ar.begin(), ar.end());
  int mn = ar[0];
  int mni = 0;
  int mx = ar.back();
  int mxi = ar.size()-1;
  while(mn < mx && mni < mxi){
    if(cnt[mx] <= cnt[mn]){
      if(k - cnt[mx] >= 0){
        int d = ar[mxi - 1];
        if(  k >= cnt[mx] * (mx-d) ){
          k -= cnt[mx] * (mx - d);
          mxi --;
          cnt[d] += cnt[mx];
          mx = d;
        }else{
          int f = k / cnt[mx];
          mx -= f;
          break;
        }
      }else{
        break;
      }
    }else{
      if(k - cnt[mn] >= 0){
        int d = ar[mni + 1];
        if(  k >= cnt[mn] * (d-mn) ){
          k -= cnt[mn] * (d-mn);
          mni ++;
          cnt[d] += cnt[mn];
          mn = d;
        }else{
          int f = k / cnt[mn];
          mn += f;
          break;
        }
      }else{
        break;
      }
    }
  }
  cout << mx - mn;
}

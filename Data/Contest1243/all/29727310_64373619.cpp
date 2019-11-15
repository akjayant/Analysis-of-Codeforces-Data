#include <bits/stdc++.h>
using namespace std;

int main(){
  int k; cin >> k;
  while(k --){
    int n; cin >> n;
    int ans = 0;
    vector<int> ar(n);
    for(int i = 0; i < n; i ++)
      cin >> ar[i];
    sort(ar.rbegin(), ar.rend());
    for(int i = 0; i < n; i ++){
      if(ar[i] >= (i+1)){
        ans = i+1;
      }else break;
    }
    cout << ans << endl;
  }
}

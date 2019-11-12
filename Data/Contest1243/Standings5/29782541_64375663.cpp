#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int q;cin>>q;
  vector<int> a;
  for(int i = 0; q > i; i++){
    int n;cin>>n;
    for(int i = 0; n > i; i++){
      int tmp;cin>>tmp;
      a.push_back(tmp);
    }
    sort(a.begin(),a.end(),greater<int>());
    if(a[a.size()-1] >= a.size()){
      cout << a.size() << endl;
    }else{
      int ans = 0;
      for(int i = 0; n > i; i++){
        ans = max(ans,min(a[i],i+1));
      }
      cout << ans << endl;
    }
    a.clear();
  }
}
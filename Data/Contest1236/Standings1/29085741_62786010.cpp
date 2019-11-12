#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105];
int main() {
  int t;
  cin>>t;
  while(t--){
    for(int i=1;i<=3;i++) cin>>a[i];
    int ans=0;
    int xx=min(a[3]/2,a[2]);
    ans+=xx*3;
    a[2]-=xx;
    ans+=min(a[2]/2,a[1])*3;
    cout<<ans<<'\n';
  }
  return 0;
}

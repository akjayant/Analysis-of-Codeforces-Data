#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int a[10005];
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int minn=100000,cnt=0,ans=0;
    for(int i=n-1;i>=0;i--){
      cnt++;
      minn=min(minn,a[i]);
      ans=max(min(minn,cnt),ans);
    }
    printf("%d\n",ans);
  }
  return 0;
}
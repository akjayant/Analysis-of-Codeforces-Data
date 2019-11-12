#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
main()
{
  int q;
  cin>>q;
  while(q--){
    int n;
    cin>>n;
    int a[n+5];
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=n;i>=1;i--){
      if(a[i]>=(n-i+1)){
        ans=n-i+1;
      }
    }
    cout<<ans<<endl;
  }
}

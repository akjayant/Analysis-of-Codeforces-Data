#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define sll      set<ll>
#define msll    multiset<ll>
#define io  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


int main()
{
  io
  ll i,j,t,n,a[1003];
  cin>>t;
  while(t--){
    cin>>n;
    vi vv;
    for(i=0;i<n;i++){
      cin>>a[i];
    }
    sort(a,a+n);
    ll ans=1;
    for(i=1;i<=n;i++){
      auto it=lower_bound(a,a+n,i)-a;
      if(n-it>=i) ans=i;
    }
    cout<<ans<<"\n";
  }


  

  return 0;
}
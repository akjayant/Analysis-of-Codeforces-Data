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
  ll i,j,t,n;
  cin>>t;
  while(t--){
    string s,t,a="",b="";
    cin>>n>>s>>t;
    ll cnt=0;
    for(i=0;i<n;i++){
      if(s[i]!=t[i]){
        cnt++;
        if(cnt%2) a=string(1,s[i])+string(1,t[i]);
        else b=string(1,s[i])+string(1,t[i]);
      }
    }
    if((cnt==2 and a[0]==b[0] and a[1]==b[1])) cout<<"Yes\n";
    else cout<<"No\n";
  }

  

  return 0;
}
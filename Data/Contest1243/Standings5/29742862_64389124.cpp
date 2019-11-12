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

vector<pair<ll,ll> > ans;
int main()
{
  io
  ll i,j,tt,n;
  string s,t;
  cin>>tt;
  while(tt--){
    ans.clear();
    cin>>n>>s>>t;
    ll hogaya=0,cnt=0;
    for(i=0;i<n;i++){
      if(s[i]==t[i]) continue;
      else{
        ll got=0;
        for(j=i+1;j<n;j++){
          if(s[j]==s[i]){
            got=1;
            swap(s[j],t[i]);
            ans.pb({j,i});
            cnt++;
            break;
          }
        }
        if(!got){
          for(j=i+1;j<n;j++){
            if(t[j]==s[i]){
              got=1;
              swap(t[j],s[i+1]);
              swap(s[i+1],t[i]);

              ans.pb({i+1,j});
              ans.pb({i+1,i});
              cnt+=2;
              break;
            }
          }
        }
        if(!got){
          hogaya=1;
          cout<<"No\n";
          break;
        }
      }
    }
    if(!hogaya){
      if(cnt<=2*n){
        cout<<"Yes\n"<<cnt<<"\n";
        for(auto it:ans) cout<<it.F+1<<" "<<it.S+1<<"\n";
      }
      else cout<<"No\n";
    }
  }

  

  return 0;
}
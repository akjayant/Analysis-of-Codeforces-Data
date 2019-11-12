#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rfr(i,x,y) for(int i=x;i>=y;i--)
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
#define __ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);

const int N=1e6,M=7,INF=1e18,MOD=1e9+7,L=10;
map<char,int> need1;
map<char,int> need2;
map<char,int> k;
vector<pair<int,int> > ans;
void solve()
{
  int n;
  cin>>n;
  string s1,s2;
  cin>>s1>>s2;
  k.clear();
  fr(i,0,n)
  {
    k[s1[i]]++;
    k[s2[i]]++;
  }
  bool can=1;
  for(auto i:k)
  {
    if(i.second%2==1)can=0;
  }
  ans.clear();
  if(can)
  {
    cout<<"Yes\n";
    fr(i,0,n)
    {
      if(s1[i]!=s2[i])
      {
        bool was=0;
        fr(j,i+1,n)
        {
          if(s2[j]==s2[i])
          {
            was=1;
            ans.push_back({i,j});
            swap(s1[i],s2[j]);
            break;
          }
        }
        if(!was)
        {
          fr(j,i+1,n)
          {
            if(s1[j]==s2[i])
            {
              was=1;
              ans.push_back({j,i+1});
              swap(s1[j],s2[i+1]);
              ans.push_back({i,i+1});
              swap(s1[i],s2[i+1]);
              break;
            }
          }
        }
      }
    }
    cout<<ans.size()<<'\n';
    fr(i,0,ans.size())
    {
      cout<<ans[i].first+1<<' '<<ans[i].second+1<<'\n';
    }
  }
  else cout<<"No\n";
}
 main()
{
		__;
    int t;
    cin>>t;
    while(t--)solve();
}

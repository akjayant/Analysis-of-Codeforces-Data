#include <bits/stdc++.h>

using namespace std;
#define fr(i,x,y) for(int i=x;i<y;i++)
#define rfr(i,x,y) for(int i=x;i>=y;i--)
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
#define __ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);

const int N=1e6,M=7,INF=1e18,MOD=1e9+7,L=10;
int mas[N];
void solve()
{
  int n;
  cin>>n;
  string s1,s2;
  cin>>s1>>s2;
  int was=0;
  char a1,a2;
  fr(i,0,n)
  {
    if(s1[i]!=s2[i])
    {
      if(was==0)
      {
        a1=s1[i];
        a2=s2[i];
        was++;
      }
      else if(was==1)
      {
        if(s2[i]==a2 && s1[i]==a1)was++;
        else {cout<<"No\n";return;}
      }
      else {cout<<"No\n";return;}
    }
  }
  if(was==1)cout<<"No\n";
  else cout<<"Yes\n";
}
 main()
{
		__;
    int t;
    cin>>t;
    while(t--)
    {
      solve();
    }
}

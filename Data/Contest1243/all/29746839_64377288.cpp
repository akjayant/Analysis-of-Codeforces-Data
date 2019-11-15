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
  fr(i,0,n)cin>>mas[i];
  sort(mas,mas+n,greater<int>());
  int ans=0;
  fr(i,0,n)
  {
    ans=max(ans,min (mas[i],i+1));
  }
  cout<<ans<<'\n';
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

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test() ull t;cin>>t;while(t--)
#define pb push_back
#define nl cout<<endl
#define MOD 1000000007
#define loop(i,start,end) for(ll i=start;i<end;i++)
#define N 100001
#define all(v) v.begin(),v.end()
#define oa(a,n) for(int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define ov(a) for(int i=0;i<a.size();i++)cout<<a[i]<<" ";nl
int main() 
{
    fastio();
    #ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    int ans[n][n];
    int dr = 1;
    bool x= 0;
    for(int i = 0;i<n;i++)
    {
      for(int j = 0;j<n;j++)
      {
        if(!x)
          ans[j][i] = dr++;
        else
          ans[n-j-1][i] = dr++;
      }
      x=!x;
    }
    loop(i,0,n)
    {
      loop(j,0,n)cout<<ans[i][j]<<" ";
      nl;
    }

  return 0;
}
 #include<bits/stdc++.h>
#define mod 1000000007
#define fr first
#define se second
#define ll long long
#define PI 3.1415926535 
#define pb push_back
#define mpr make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define IOS1 ios_base::sync_with_stdio(false);
#define IOS2    cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll power(ll a,ll b)
{
    ll res =1;
    while(b)
    {
        if(b&1) res = (res%mod*a%mod)%mod;
        b/=2;
        a = (a%mod*a%mod)%mod;
    }
    return res;
}
ll sieve[1000005];
void pre()
{
    sieve[0]=1;
    sieve[1]=1;
    for(int i=2;i<1000005;i++)
    {
        if(sieve[i]==0)
        {
            for(int j=2*i;j<1000005;j+=i)
            {
                sieve[j]=1;
            }
        }
    }
}
ll p[4][100005];
ll indeg[100005];
vector<ll>adj[100005];
vector<ll>v;
ll vis[100005];
ll ans3[100005];
void dfs(ll s)
{
  vis[s]=1;
  v.pb(s);
  for(auto it : adj[s])
  {
    if(!vis[it])
    {
      dfs(it);
    }
  }
}
signed main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
      
      IOS1
      IOS2
      
      ll n;
      cin>>n;
      v.pb(0);
      for(int i=1;i<=3;i++)
      {
        for(int j=1;j<=n;j++)
        {
            cin>>p[i][j];
        }
      }
      ll f=0;
      ll st = 0;
      for(int i=0;i<n-1;i++)
      {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        indeg[a]++;
        indeg[b]++;
        if(indeg[a]>=3)
            f=1;
       if(indeg[b]>=3)
            f=1;
         
      }
      for(int i=1;i<=n;i++)
      {
        if(indeg[i]==1)
        {
          st=i;
          break;
        }
      }
      dfs(st);
      if(f) cout<<"-1"<<endl;
      else
      {
        ll ans = 1e18;
        ll ch1=-1,ch2=-1,ch3=-1;
          for(int i=1;i<=3;i++)
          {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    if(i!=j && i!=k && j!=k)
                    {
                      ll ans1 = p[i][v[1]]+p[j][v[2]]+p[k][v[3]]; 
                       for(int l=4;l<=n;l++)
                       {
                          if(l%3==1)
                          ans1+=p[i][v[l]];
                         else if(l%3==2)
                            ans1+=p[j][v[l]];
                        else ans1+=p[k][v[l]];
                       }
                       if(ans1<ans)
                       {
                        ans = ans1;
                        ch1 = i;
                        ch2 = j;
                        ch3 = k;
                       }
                    }
                }
            }
          }
          cout<<ans<<endl;
          ans3[v[1]] = ch1;
          ans3[v[2]] = ch2;
          ans3[v[3]] = ch3;
          for(int l=4;l<=n;l++)
          {
            if(l%3==1) ans3[v[l]]= ch1;
            else if(l%3==2) ans3[v[l]]=ch2;
            else ans3[v[l]]=ch3;
          }
          for(int l=1;l<=n;l++)
          {
            cout<<ans3[l]<<" ";
          }
      }
}



















#include<bits/stdc++.h>
#include<list>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAX 1e18 
#define N 100005
ll mod1 = 998244353;
ll mod= 1e9;
//ll p = 100;
bool comp(pair<int,int> a,pair<int,int> b)
{
  return a.ss<b.ss;  
}

ll a[3][N];
ll e[N];
ll arr[N];
vector<int> g[N];
ll dfs(int x,int y,int j,int i)
{
  ll sum = a[j][x];
  for(auto v:g[x])
  {
    if(v == y)
    continue;

    for(int k = 0;k<3;++k)
    {
      if(k!=j&&k!=i)
      sum+= dfs(v,x,k,j);
    }
  }

  return sum;
}
void dfss(int x,int y,int j,int i)
{
  arr[x] = j;
  for(auto v:g[x])
  {
    if(v == y)
    continue;

    for(int k = 0;k<3;++k)
    {
      if(k!=j&&k!=i)
      dfss(v,x,k,j);
    }
  }

}

void solve()
{
  ll n;
  cin>>n;

  for(int i = 0;i<3;++i)
  for(int j = 1;j<=n;++j)
  cin>>a[i][j];

  for(int i =1;i<n;++i)
  { int x,y;
    cin>>x>>y;
    e[x]++;
    e[y]++;
    g[x].pb(y);g[y].pb(x);
    if(e[x]>2||e[y]>2)
    {
      cout<<-1;return;
    }
  }
  
  ll c1,c2;
  ll ans = 1e17;

  

  if(g[1].size()==1)
  {
  int  p1 = g[1][0];

    for(int i =  0;i<3;++i)
    for(int j = 0;j<3;++j)
    {
      if(i==j)
      {
          continue;
      }
      ll x  =a[i][1] + dfs(p1,1,j,i);
      if(ans> x)
      {
        ans = x;
        c1 =  i;c2 = j;
      }

    }

    arr[1] = c1;

    dfss(p1,1,c2,c1);

  }
  else
  {
    int p1 = g[1][0];
    int p2 = g[1][1];
    int c3 ;
    for(int i =  0;i<3;++i)
    for(int j = 0;j<3;++j)
    for(int k = 0;k<3;++k)
    {
      if(i==j||j==k||i==k)
      {
          continue;
      }
      ll x  =a[i][1] + dfs(p1,1,j,i) + dfs(p2,1,k,i);
      if(ans> x)
      {
        ans = x;
        c1 =  i;c2 = j;c3 = k;
      }

    }
    arr[1] = c1;
    dfss(p1,1,c2,c1) ; dfss(p2,1,c3,c1);

  }

  cout<<ans<<endl;
  for(int i = 1;i<=n;++i)
  cout<<arr[i]+1<<" ";
  



}


            
int main()
{
         
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
                    	
ll t=1;
//cin>>t;

while(t--)
{
  solve(); 
  cout<<"\n";    		
}
return 0;

}            
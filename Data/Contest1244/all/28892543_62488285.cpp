#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
 
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
 typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 
#define int         long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define mp          make_pair
#define all(a)      (a).begin(),(a).end()
#define FF           first
#define SS           second
#define sz(x)       (int)x.size()
#define endl        '\n'
//#define hell          1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
// mp::cpp_int
 
const int hell= 1000000007;
 
 int power(int a,int b)
 {
  if(b==0)return 1LL;
  if(b==1)return a;
  int t=power(a,b/2);
  t*=t;
  t%=hell;
  if(b&1)return (t*a)%hell;
  else return t;
 }

 int inverse(int a)
 {
    return power(a,hell-2);
 }
 
int pw(int a,int b)
{
  int x=a;
  rep(i,1,b){a=a*x;
    a%=10000000000LL;}
  return a;
}
 
int gcd(int a,int b)
{   
  if(b==0)return a;
  return gcd(b-a%b,a%b);
} 

int cost[100010][3];
vi g[100010];

int cnt=0,x,y;
int ans=hell*hell;
int vis[100010]={0};
int gg[100010]={0};

int dfs(int node,int p1,int p2)
{
   vis[node]=1;
    for(auto x:g[node])
    {
       if(!vis[x])
       {   
           rep(j,0,3)
           if(j!=p1&&j!=p2)
            { cnt+=dfs(x,j,p1);
              break;
            }
       }
    }

   return cost[node][p1];
}



int dfs1(int node,int p1,int p2)
{
  gg[node]=p1;
  //cout<<node<<" "<<p1<<endl;
  vis[node]=true;

   for(auto x:g[node])
    {
       if(!vis[x])
       {   
           rep(j,0,3)
           if(j!=p1&&j!=p2)
            { dfs1(x,j,p1);
              break;
            }
       }
    }

   
}


int solve()
{  

int n;
cin>>n;
rep(j,0,3)
rep(i,1,n+1)
{
   cin>>cost[i][j];
}

rep(i,0,n-1)
{
  int x,y;
  cin>>x>>y;
  g[x].pb(y);
  g[y].pb(x);
  if(g[x].size()>2)
  {
    cout<<-1;
    return 0;
  }
    if(g[y].size()>2)
  {
    cout<<-1;
    return 0;
  }
}

int node=0;
rep(i,1,n+1)
if(g[i].size()==1)
{
  node=i;
  break;
}
//cout<<node<<endl;

memset(vis,0,sizeof(vis));
dfs(node,0,1);
cnt+=cost[node][0];
if(ans>cnt)
{ 
  ans=cnt;
  x=0,y=1;
}
cnt=0;
memset(vis,0,sizeof(vis));
dfs(node,0,2);
cnt+=cost[node][0];
if(ans>cnt)
{
  ans=cnt;
  x=0,y=2;
}
cnt=0;
memset(vis,0,sizeof(vis));
dfs(node,1,0);
cnt+=cost[node][1];
if(ans>cnt)
{ ans=cnt;
  x=1,y=0;
}
cnt=0;
memset(vis,0,sizeof(vis));
dfs(node,1,2);
cnt+=cost[node][1];
if(ans>cnt)
{  ans=cnt;
  x=1,y=2;
}
cnt=0;
memset(vis,0,sizeof(vis));
dfs(node,2,0);
cnt+=cost[node][2];
if(ans>cnt)
{
  ans=cnt;
  x=2,y=0;
}
cnt=0;
memset(vis,0,sizeof(vis));
dfs(node,2,1);
cnt+=cost[node][2];
if(ans>cnt)
{ 
  ans=cnt;
  x=2,y=1;
}
memset(vis,0,sizeof(vis));

dfs1(node,x,y);
//cout<<node<<" "<<x<<" "<<y<<endl;
 
 cout<<ans<<endl;
 rep(i,1,n+1)
 { 
  cout<<gg[i]+1<<" ";
 }


return 0;
}
 
signed main()
{  int t=1;
 
 ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
  
   cin.exceptions(cin.failbit);                                                                    
     
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);                                   
    #endif                                   
   
 
  clock_t time_req;
 
    // Without ung pow function
                                                                                                                   
 //cin>>t;
 
    int k=1;
     
   while(t--)
     {
      //cout<<"Case #"<<k<<":"<<" ";k++;
      solve();
     }
        exit(0);
 
         time_req = clock() - time_req;
    cout <<endl<< "Processor time taken is "
      << (double)time_req/CLOCKS_PER_SEC << " seconds" << endl;
 
 
    return 0;
 
}

#include<bits/stdc++.h>
#define MOD 1e9+7
using namespace std;
#define  pp push_back
#define  po pop_back
#define  mp make_pair
#define clr(a) memset(a,0,sizeof(a))
#define neg(a) memset(a,-1,sizeof(a))
#define fas(a) memset(a,false,sizeof(a))
#define debug(x) cout<<#x<<": "<<x<<endl
#define debug1(x) cout<<#x<<": "<<x<<" "
#define rev(x) reverse(x.begin(), x.end())
#define int long long 
#define F first
#define S second
//int a[2000];
void printvector(std::vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<""<<endl;}
void printarray(int a[],int n){for (int i = 0; i < n; ++i){cout<<a[i]<<" ";}cout<<""<<endl;}
 
 

 

void  solve()
{
  int n;cin>>n;
  std::vector<int> v[n];
  int dir=1;
  int now=0; 
  int count=1;
  while(count<=n*n)
  {
     v[now].pp(count);
     count++;
     now+=dir;
     if(now<0||now>=n){dir=-dir;now+=dir;}
      
  }

  for(int i=0;i<n;i++)
  {
     printvector(v[i]);
  }

}




 int32_t main() 
{

  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    
   solve();

return 0;

}
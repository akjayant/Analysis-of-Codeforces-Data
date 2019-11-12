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
 
int power(int x,int n,int M)
{
  int result=1;
  while(n!=0)
  {
  if(n%2==1)result=(result*x)%M;
  x=(x*x)%M;
  n=n/2;


  }
 

 return result;

} 

 

void  solve()
{
   int mod=MOD;
   int n,m;cin>>n>>m;
   int temp=(power(2,m,mod)+mod-1)%mod;
   temp=power(temp,n,mod);
   cout<<temp<<endl;
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
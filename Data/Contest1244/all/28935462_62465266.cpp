#include<bits/stdc++.h>
#include<list>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define MAX 1e18 
#define N 300005
ll mod1 = 998244353;
ll mod= 1e9;
//ll p = 100;
bool comp(pair<int,int> a,pair<int,int> b)
{
  return a.ss<b.ss;  
}
ll n;

void solve()
{
  ll a,b,c,d,k;

  cin>>a>>b>>c>>d>>k;
  ll x,y;

  x = a/c;y = b/d;

  if(a%c)
  x++;
  if(b%d)
  y++;


  if(x+y>k)
  cout<<-1;
  else
  {
    cout<<x<<" "<<k-x;
  }
  



}


            
int main()
{
         
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
                    	
ll t=1;
cin>>t;

while(t--)
{
  solve(); 
  cout<<"\n";    		
}
return 0;

}            
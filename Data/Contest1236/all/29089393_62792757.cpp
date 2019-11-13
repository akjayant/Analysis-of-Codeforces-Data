#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
 
void printvector(vector<ll> v)
{
    for(int i=0;i<v.size();i++)
    {
      cout<<v[i]<<" ";
    }
    cout<<endl;
}
 

ll px(ll x, ll y) 
{ 
    ll res = 1;
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x)%1000000007; 
        y = (y >> 1)%1000000007; 
        x = (x * x)%1000000007; 
    } 
    return res; 
} 
 

int main()
{
   ll n,i,j,k,x,l,m;

   vector<ll> v;

   cin>>n>>m;

   ll tmp=px(2,m)%1000000007;

    cout<<px(tmp-1,n)%1000000007;

}
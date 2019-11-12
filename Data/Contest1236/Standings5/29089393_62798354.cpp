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
 



int main()
{
   ll n,i,j,k,x,l,m;

   vector<ll> v;

    cin>>n;

    ll a[n][n];

    ll num=1;

    for(j=0;j<n;j++)
    {
        if(j%2==0)
        {
          for(i=0;i<n;i++)
          {
              a[i][j]=num++;
          }
        }
        else
        {
          for(i=n-1;i>=0;i--)
          {
            a[i][j]=num++;
          }
        }
    }

    for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
          cout<<a[i][j]<<" ";
        cout<<endl;
     }

}
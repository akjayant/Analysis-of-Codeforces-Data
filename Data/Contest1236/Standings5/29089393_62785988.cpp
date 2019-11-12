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
   ll n,i,j,k,x,l;

   vector<ll> v;

   ll t;
   cin>>t;
   while(t--)
   {
      ll a,b,c;
      cin>>a>>b>>c;
      ll stones=a+b+c;
      for(i=0;i<100;i++)
      {
        if(b-i>=0 && c-2*i>=0)
          continue;
        else
          break;
      }

      i--;

      b=b-i;
      c=c-2*i;

       for(i=0;i<100;i++)
        {
          if(a-i>=0 && b-2*i>=0)
            continue;
          else
            break;
        }

      i--;

      a=a-i;
      b=b-2*i;

      cout<<stones-(a+b+c)<<endl;
   }
}
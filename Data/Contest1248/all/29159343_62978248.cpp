#include<bits/stdc++.h>
const int  mod=1e9+7;
const int N = 1e5+7;
const int inf= 0x3f3f3f3f;
typedef long long ll;
using namespace std;
int main()
{
   int zs;ios::sync_with_stdio(false);
   cin>>zs;
   while(zs--)
   {

       ll n;cin>>n;
       ll a1=0,a2=0;
       for(int i=0;i<n;i++)
       {
           int h;cin>>h;
           if(h%2) a1++;
           else a2++;
       }
       cin>>n;
       ll b1=0,b2=0;
       for(int i=0;i<n;i++)
       {
           int h;cin>>h;
           if(h%2) b1++;
           else b2++;
       }
       cout<<b1*a1+b2*a2<<endl;
   }
}

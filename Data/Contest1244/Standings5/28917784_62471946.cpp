#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define _IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e5+9,inf=1e18,mod=1e9+7;

int main()
{
    _IO;
   int t;cin>>t;
   while(t--)
   {
       int n;
       string s;
       cin>>n>>s;
       int l=n+1,r=0;
       int ans=n;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='1')
           {
               if(l==n+1)l=i+1;
               r=i+1;
           }
       }
        ans=max(r*2,ans);
        ans=max(ans,(n-l+1)*2);
        cout<<ans<<"\n";

   }


}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=400005;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int t;
    ios::sync_with_stdio(0);
   cin>>t;
     while(t--)
     {
        int a,b,c;
         cin>>a>>b>>c;
         int ans=0;
         for(int i=0;i<=100;i++)
         {
             for(int j=0;j<=100;j++)
             {
                if(i<=a&&2*i+j<=b&&2*j<=c)
                    ans=max(ans,3*(i+j));
             }
         }
        cout<<ans<<endl;
     }
    
    
    
    
    
    
    
    return 0;
}

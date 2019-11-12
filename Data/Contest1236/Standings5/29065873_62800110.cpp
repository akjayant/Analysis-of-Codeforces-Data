
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=400005;
ll mod=1e9+7;
int ans[305][305];
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
#endif
   int n;
   cin>>n;
   int cnt=0;
   for(int j=1;j<=n;j++)
   {
        if(j%2)
        {
           for(int i=1;i<=n;i++)
            ans[i][j]=++cnt;
        }
        else {
            for(int i=n;i>=1;i--)
                ans[i][j]=++cnt;
        }
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
           cout<<ans[i][j]<<' ';
       cout<<endl;
   }
    
    
    
    
    return 0;
}

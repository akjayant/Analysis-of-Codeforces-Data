#include <bits/stdc++.h>
#define ls rt*2
#define rs rt*2+1
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;

int a[1010];
int vis[1010];
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
//        int vis[1010]= {0};
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            vis[a[i]]++;
        }
        int ans=0;
        for(int i=1000; i>=1; i--)
        {
            vis[i]+=vis[i+1];
            if(vis[i]>=i)
            {
                ans=i;
                break;
            }
        }
//        int ans=0;
        cout<<ans<<endl;

    }
}

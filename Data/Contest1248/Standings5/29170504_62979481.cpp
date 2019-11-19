#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+6;

int a[N],b[N],n,m;
int main()
{
    int cas;cin>>cas;
    while(cas--)
    {
        cin>>n;int ji=0,ou=0;
        for(int i=1;i<=n;i++)
        {scanf("%d",&a[i]);
        if(a[i]%2==0)ou++;
        else ji++;
        }
        cin>>m;
        ll ans=0;

        for(int i=1;i<=m;i++)
        {scanf("%d",&b[i]);
        if(b[i]%2==0)ans+=1ll*ou;
        else ans+=1ll*ji;
        }

        
        
        cout<<ans<<endl;

    }


    return 0;
}
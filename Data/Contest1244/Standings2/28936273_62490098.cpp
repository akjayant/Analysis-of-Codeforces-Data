#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 200000
#define ll long long

ll dp[mx],ans[mx];
vector<ll>vc;
int run(ll diff,int n,ll thrs)
{
    int po=1;
    for(int i=1;i<=n;i++)ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        while(po<=i)po++;
        while(po<=n&&vc[po]-vc[i]<=diff)po++;
        if(po<=n)
        {
           ans[i]+=(dp[n]-dp[po-1])-((n-po+1)*(vc[i]+diff));
        }
        ans[i]+=1LL*(i-1)*vc[i]-dp[i-1];
        //if(po>n)continue;
        //ans[i]+=vc[n]-vc[po-1];
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]<=thrs)return 1;
    }
    for(int i=1;i<=n;i++)ans[i]=0;
    po=n;
    for(int i=n;i>=1;i--)
    {
        while(po>=i)po--;
        while(po>=1&&vc[i]-vc[po]<=diff)po--;
        if(po>=1)
        {
            ans[i]+=(vc[i]-diff)*po-dp[po];
        }
        if(i<n)
        {
           ans[i]+=(dp[n]-dp[i])-1LL*(n-i)*vc[i];
        }
    }
      for(int i=1;i<=n;i++)
    {
        if(ans[i]<=thrs)return 1;
    }
    return 0;
}
int main()
{

    int i,j,k,l,m,n;
    vc.pb(-1);
    ll Kth;
    cin>>n>>Kth;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&l);
        vc.pb(l);
    }
    sort(vc.begin(),vc.end());
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+vc[i];
    }
    ll lo=0,high=1e9,ans=-1;
 //   vc.pb(2e9);
    while(lo<=high)
    {
        ll mid=(lo+high)>>1;
        if(run(mid,n,Kth)){
           ans=mid;
           high=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;



}

/*jai mata di
let's rock*/
#include<bits/stdc++.h>
using namespace std;
const int N=100004;
long long int a[N];
long long sum[N];
int main()
{
    int n;
    long long k;
    scanf("%d %I64d",&n,&k);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=0,r=1e9;
    int ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        long long kx=1e18;
        for(i=1;i<=n;i++)
        {
            long long val=i*1LL*a[i]-sum[i];
            int ax=a[i]+mid;
            int lt=i,rt=n;
            int idx=-1;
            while(lt<=rt)
            {
                int m=(lt+rt)/2;
                if(a[m]>=ax)
                {
                    idx=m;
                    rt=m-1;
                }
                else lt=m+1;
            }
            if(idx!=-1)
                val=val+sum[n]-sum[idx-1]-1LL*(n-idx+1)*ax;
            kx=min(kx,val);

            long long val1=sum[n]-sum[i-1]-1LL*(n-i+1)*a[i];
            ax=a[i]-mid;
            lt=1,rt=i;
            idx=-1;
            while(lt<=rt)
            {
                int m=(lt+rt)/2;
                if(a[m]<=ax)
                {
                    idx=m;
                    lt=m+1;
                }
                else rt=m-1;
            }
            if(idx!=-1)
                val1=val1+ax*1LL*idx-sum[idx];
            kx=min(kx,val1);
        }
        if(kx<=k)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;

}

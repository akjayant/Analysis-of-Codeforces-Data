#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+7;
int n,m,x;
ll a[N];
ll ans;
int main()
{

    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }
    if(n==1){
        printf("%lld\n",a[1]*a[1]);
        return 0;
    }
    sort(a+1,a+1+n);
    ll sum1=0,sum2=0;
    for(int i=1; i<=n; i++){
        if(i+i<=n){
            sum1+=a[i];
        }
        else
            sum2+=a[i];
    }
    ans=sum1*sum1+sum2*sum2;
    printf("%lld\n",ans);
}

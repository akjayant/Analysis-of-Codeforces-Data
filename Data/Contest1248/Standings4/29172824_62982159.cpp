#include<bits/stdc++.h>
using namespace std;
#define maxn 100008
#define int long long
int n;
int a[maxn];
int sum[maxn];
signed main(){
    scanf("%lld",&n);
    int ans=0;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int sum1=0;
    int sum2=0;
    for(int i=1;i<=n/2;i++){
        sum1+=a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        sum2+=a[i];
    }
    cout<<(sum1*sum1+sum2*sum2)<<endl;
    return 0;
}
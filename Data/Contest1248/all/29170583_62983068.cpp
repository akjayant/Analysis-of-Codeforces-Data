#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int t=n/2;
    ll s1=0,s2=0;
    for(int i=1;i<=n;i++){
        if(i<=t)
            s1+=a[i];
        else s2+=a[i];
    }
    ll ans=s1*s1+s2*s2;
    printf("%lld\n",ans);
}
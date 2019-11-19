#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
ll a[maxn],sum[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int mid=n/2;
    ll ans=sum[mid]*sum[mid];
    ans+=(sum[n]-sum[mid])*(sum[n]-sum[mid]);
    cout<<ans<<endl;
    return 0;
}
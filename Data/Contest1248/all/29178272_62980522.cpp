#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;
ll a[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ll m=0;
    for(int i=1;i<=(n+1)/2;i++) m+=a[i];
    ll mm=0;
    for(int i=(n+1)/2+1;i<=n;i++) mm+=a[i];
    ll ans=m*m+mm*mm;
    cout<<ans<<endl;


    return 0;
}

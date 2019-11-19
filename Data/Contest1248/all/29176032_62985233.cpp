#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
typedef long long ll;
int ans;
ll a[100500];
int main(){
    int tt,n,m;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    ll ans=0,x=0,y=0;
    rep(i,1,n/2) x+=a[i];
    rep(i,n/2+1,n) y+=a[i];
    printf("%lld\n",x*x+y*y);
    return 0;
}
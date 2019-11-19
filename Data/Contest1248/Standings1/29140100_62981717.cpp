#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
typedef long long ll;
const int maxn=(int)2e5+100;
const int mod=(int)1e9+7;
int n,a[maxn];
int main(){
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    ll x=0,y=0;
    int mid=n/2;
    rep(i,1,mid) x+=a[i];
    rep(i,mid+1,n) y+=a[i];
    printf("%lld\n",x*x+y*y);
}
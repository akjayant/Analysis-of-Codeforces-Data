#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n; ll k;
ll a[maxn], mn[maxn], mx[maxn];
bool check1(ll mid){
    int j=n; ll sum=0;
    for(int i=1;i<=n;i++) mn[i]=0;
    for(int i=n-1;i>=1;i--){
        while(j>=1&&a[j]>a[i]+mid) sum+=a[j], j--;
        mn[i]=sum-(a[i]+mid)*(n-j);
    }
    j=1; sum=0;
    for(int i=2;i<=n;i++){
        while(j<=n&&a[j]<a[i]) sum+=a[j], j++;
        mn[i]+=a[i]*(j-1)-sum;
    }
    for(int i=1;i<=n;i++) if(mn[i]<=k) return true;
    return false;
}
bool check2(ll mid){
    int j=n; ll sum=0;
    for(int i=1;i<=n;i++) mx[i]=0;
    for(int i=n-1;i>=1;i--){
        while(j>=1&&a[j]>a[i]) sum+=a[j], j--;
        mx[i]=sum-a[i]*(n-j);
    }
    j=1; sum=0;
    for(int i=2;i<=n;i++){
        while(j<=n&&a[j]<a[i]-mid) sum+=a[j], j++;
        mx[i]+=(a[i]-mid)*(j-1)-sum;
    }
    for(int i=1;i<=n;i++) if(mx[i]<=k) return true;
    return false;
}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll lb=-1, ub=1e9+2;
    while(ub-lb>1){
        ll mid=(lb+ub)>>1;
        if(check1(mid)||check2(mid)) ub=mid;
        else lb=mid;
    }
    printf("%lld\n",ub);
    return 0;
}

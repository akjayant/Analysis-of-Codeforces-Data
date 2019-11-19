#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
ll a[100010], trakm[100010], n, trakm1[100010];
ll fn(ll x){
    ll cnt=0, tmp=0, mn=1e15, tmp1, p1=0;
    for(int i=0; i<n; ++i){
        if(i>0){
            tmp+=cnt*(a[i]-a[i-1]);
        }
        for(p1; p1<n; ++p1){
            if(a[p1]>=a[i]+x){
                break;
            }
        }
        tmp1=tmp+trakm[p1]-(n-p1)*(a[i]+x);
        mn=min(mn, tmp1);
        ++cnt;
    }
    cnt=0, tmp=0, tmp1, p1=n-1;
    for(int i=n-1; i>=0; --i){
        if(i<n-1){
            tmp+=cnt*(a[i+1]-a[i]);
        }
        for(p1; p1>=0; --p1){
            if(a[p1]<=a[i]-x){
                break;
            }
        }
        tmp1=tmp-trakm1[p1]+(p1+1)*(a[i]-x);
        mn=min(mn, tmp1);
        ++cnt;
    }
    return mn;
}
int main(){
    ll k;
    while(cin>>n>>k){
        for(int i=0; i<n; ++i){
            scanf("%lld",a+i);
        }
        sort(a, a+n);
        trakm[n]=0;
        for(int i=n-1; i>=0; --i){
            trakm[i]=trakm[i+1]+a[i];
        }
        trakm1[0]=a[0];
        for(int i=1; i<n; ++i){
            trakm1[i]=trakm1[i-1]+a[i];
        }
        ll ans=0;
        ll st = 0, nd = 1e9, md, tmp;
        while(st<nd){
            md=(st+nd)/2;
            tmp=fn(md);
            if(tmp<=k){
                nd=md;
            }
            else{
                st=md+1;
            }
        }
        cout<<nd<<endl;
    }
  return 0;
}



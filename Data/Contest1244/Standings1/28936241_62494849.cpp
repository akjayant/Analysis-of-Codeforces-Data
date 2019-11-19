#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define maxn 101000
#define maxm 201000
typedef long long ll;
ll a[maxn],n,k;
void work(){
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    ll l=1,lsize=1,r=n,rsize=1;
    while(l<r){
        if(lsize<rsize){
            ll t=a[l+1]-a[l];
            if(t*lsize<=k){
                k-=1LL*t*lsize;
                l++;lsize++;
            }else{
                ll v=k/lsize;
                ll ck=k%lsize;
                printf("%lld\n",a[r]-(a[l]+v));
                return;
            }
        }else{
            ll t=a[r]-a[r-1];
            if(t*rsize<=k){
                k-=1LL*t*rsize;
                r--;rsize++;
            }else{
                ll v=k/rsize;
                ll ck=k%rsize;
                printf("%lld\n",a[r]-v-a[l]);
                return;
            }
        }
        //printf("%lld %lld %lld %lld %lld\n",l,lsize,r,rsize,k);
    }
    puts("0");
}
int main(){
    int t=1;
    while(t--)work();
}

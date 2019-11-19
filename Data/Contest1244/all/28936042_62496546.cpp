#include<bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
#define drap(i,n,s) for(int i=n;i>=s;i--)
using namespace std;
typedef long long ll;
#define N 200100
int n,a[N];
ll k;
int main(){
    cin>>n>>k; rap(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(a[l+1]==a[l]&&l<r) l++;
    while(a[r-1]==a[r]&&l<r) r--;
    //[1,l] same || [r,n] same
    while(k&&l<r){
        int llen=l,rlen=n-r+1;
        if(llen<=rlen){
            ll mval=min(1ll*a[l+1]-a[l],k/llen);
            k-=mval*llen;
            if(k<llen) k=0;
            a[l]+=mval;
            while(a[l+1]==a[l]&&l<r) l++;
        }
        else {
            ll mval=min(1ll*a[r]-a[r-1],k/rlen);
            k-=mval*rlen;
            if(k<rlen) k=0;
            a[r]-=mval;
            while(a[r-1]==a[r]&&l<r) r--;
        }
    }
    printf("%d\n",a[r]-a[l]);
    return 0;
}
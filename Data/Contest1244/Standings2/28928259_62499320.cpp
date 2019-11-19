#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Mx=2e5+10;
int n,l,r;
LL a[Mx],k;
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    l=1;r=n;
    while(1){
        LL disl=a[l+1]-a[l];
        LL disr=a[r]-a[r-1];
        if(l<(n-r+1)){
            if(k<l*disl){
                LL di=k/l;
                printf("%lld",a[r]-a[l]-di);
                return 0;
            }
            k-=l*disl;
            l++;
        }else{
            if(k<(n-r+1)*disr){
                LL di=k/(n-r+1);
                printf("%lld",a[r]-a[l]-di);
                return 0;
            }
            k-=(n-r+1)*disr;
            r--;
        }
        while(r!=1&&a[r-1]==a[r])r--;
        while(l!=n&&a[l+1]==a[l])l++;
        if(l>=r)return puts("0"),0;
    }
}
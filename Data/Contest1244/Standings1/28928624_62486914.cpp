#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100005;
ll m;
int n,n1;
ll a[maxn],s[maxn];
int main(){
    scanf("%d%lld",&n,&m);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    int n1=1; s[1]=1;
    for (int i=2;i<=n;i++)
        if (a[i]!=a[i-1]) a[++n1]=a[i],s[n1]=1;
        else s[n1]++;
    n=n1;
    //for (int i=1;i<=n;i++) printf("%lld %lld\n",a[i],s[i]);
    int l=1,r=n; ll ansl=a[l],ansr=a[r];
    while (m){
        if (l==r) break;
        if (s[l]<s[r]) {
            if ((a[l+1]-a[l])*s[l]>=m) ansl=a[l]+m/s[l],m=0;
            else s[l+1]+=s[l],ansl=a[l+1],m-=(a[l+1]-a[l])*s[l],l++;
        } else {
            if ((a[r]-a[r-1])*s[r]>=m) ansr=a[r]-m/s[r],m=0;
            else s[r-1]+=s[r],ansr=a[r-1],m-=(a[r]-a[r-1])*s[r],r--;
        }
    }
    printf("%lld\n",ansr-ansl);
    return 0;
}

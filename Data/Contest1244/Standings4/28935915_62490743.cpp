#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100010];
inline ll read() {
    ll x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int main() {
    long long n=read(),k=read();
    for (int i=1;i<=n;i++) {
        a[i]=read();
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    for (int i=1;i<=n;i++) 
        if (a[i]==a[l]) l=i;
        else break;
    for (int i=n;i>=1;i--)
        if (a[i]==a[r]) r=i;
        else break;
    long long ans=0;
    while (l<r) {
        if (l<n-r+1) {
            if (k>=l*(a[l+1]-a[l])) {
                k-=l*(a[l+1]-a[l]);
                ++l;
                for (int i=l;i<=n;i++)
                    if (a[i]==a[l]) l=i;
                    else break;
            }
            else {
                ans=k/l;break;
            }
        } else {
            if (k>=(n-r+1)*(a[r]-a[r-1])) {
                k-=(n-r+1)*(a[r]-a[r-1]);
                --r;
                for (int i=r;i>=1;i--) {
                    if (a[i]==a[r]) r=i;
                    else break;
                }
            }
            else {
                ans=k/(n-r+1);break;
            }
        }
    }
    if (l>=r) printf("0\n");
    else cout<<a[r]-a[l]-ans<<endl;
    return 0;
}
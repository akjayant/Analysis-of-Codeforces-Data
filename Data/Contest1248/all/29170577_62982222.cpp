#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    long long x=0,y=0;
    for(int i=0;i<n/2;i++) {
        x+=a[i];
    }
    for(int i=n/2;i<n;i++) {
        y+=a[i];
    }
    printf("%lld\n",x*x+y*y);
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
const int N=100000+10;
int n,x,y;
int a[N];
signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    int i;
    for(i=1;i<=(n>>1);i++)
        x+=a[i];
    for(;i<=n;i++)
        y+=a[i];
    printf("%lld",x*x+y*y);
    return 0;
}
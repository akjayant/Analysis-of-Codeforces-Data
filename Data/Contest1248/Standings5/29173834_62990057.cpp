#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll b1=0,b2=0;
    for(int i=1;i<=n/2;i++){
        b1+=a[i];
    }
    for(int i=n/2+1;i<=n;i++){
        b2+=a[i];
    }
    printf("%lld",b1*b1+b2*b2);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 100005;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int k=n/2;
    ll x=0,y=0;
    for(int i=1;i<=k;i++){
        x+=a[i];
    }
    for(int i=k+1;i<=n;i++){
        y+=a[i];
    }
    x=x*x+y*y;
    printf("%lld\n",x);
    return 0;
}


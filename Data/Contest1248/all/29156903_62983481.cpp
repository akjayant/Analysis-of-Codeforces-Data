#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define N 100005
ll a[N];
int n;
ll h; ll w;



int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n/2;++i) h+=a[i];
    for(int i=n/2+1;i<=n;++i) w+=a[i];
    printf("%lld\n",h*h+w*w);
    return 0;
}




















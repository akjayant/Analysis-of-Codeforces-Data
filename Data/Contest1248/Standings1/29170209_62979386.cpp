#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 2e6+5;
const ll mod = 1e9+7;


int n;
int a[maxn];

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a+i);
    sort(a+1,a+1+n);
    ll x = 0, y = 0;
    for(int i = 1; i <= n; i++){
        if(i <= n/2) y += a[i];
        else x += a[i];
    }
    printf("%lld\n", x*x+y*y);
    return 0;
}

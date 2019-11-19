#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e4 + 5, M = 3e5 + 5;

int main(){
    ll n;
    scanf("%lld", &n);
    int cnt = 0;
    for(ll i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            ++cnt;
            while(n % i == 0)n /= i;
            if(cnt == 1 && n == 1){
                printf("%lld\n", i);
                exit(0);
            }
            if(cnt > 1)
                exit(puts("1"));
        }
    }
    if(cnt == 0)
        printf("%lld\n", n);
    else puts("1");
}

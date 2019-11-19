#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 2 * N + 5;

int n, m;
ll a[3], b[3];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        a[0] = a[1] = b[0] = b[1] = 0;
        for(int i = 0 ; i < n ; ++i){
            int x;
            scanf("%d", &x);
            ++a[x % 2];
        }
        scanf("%d", &m);
        for(int i = 0 ; i < m ; ++i){
            int x;
            scanf("%d", &x);
            ++b[x % 2];
        }
        printf("%lld\n", (a[0] * b[0]) + (a[1] * b[1]));
    }
}
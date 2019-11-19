/*
 * Kickstart 2019 - Round A
 * Parcels
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define fi first
#define se second
#define mk make_pair
using namespace std;
const int MAXN = static_cast<const int>(1e5 + 5);
const int MOD = static_cast<const int>(1e9 + 7);
const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
int a[MAXN];


int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    LL sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n/2; ++i)  sum1 += a[i];
    for(int i = n/2 + 1; i <= n; ++i)  sum2 += a[i];
    printf("%lld\n", sum1*sum1 + sum2*sum2);
    /*
    int op = 1;
    LL sumx = 0, sumy = 0;
    bool odd = false;
    if(n&1)  odd = true, n-=1;
    for(int i = 1; i <= n; i+=2){
        if(op){
            sumx += a[i];
            sumy += a[i+1];
        }else{
            sumx += a[i+1];
            sumy += a[i];
        }
        op ^= 1;
    }
    if(odd){
        printf("%lld\n", max((sumx+a[n+1])*(sumx+a[n+1]) + sumy*sumy,
                             sumx*sumx + (sumy+a[n+1])*(sumy+a[n+1])));
    }else{
        printf("%lld\n", sumx*sumx + sumy*sumy);
    }
     */
    return 0;
}


/*
4
3 0
0 0 0
*/
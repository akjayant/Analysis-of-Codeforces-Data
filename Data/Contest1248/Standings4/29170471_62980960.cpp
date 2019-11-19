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
int p[MAXN], q[MAXN];


int main(){
    int _;
    scanf("%d", &_);
    while(_--){
        int n;
        scanf("%d", &n);
        int oddp = 0, evenp = 0;
        int oddq = 0, evenq = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &p[i]);
            if(p[i]&1)  ++oddp;
            else ++evenp;
        }
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i){
            scanf("%d", &q[i]);
            if(q[i]&1)  ++oddq;
            else ++evenq;
        }
//        cout << oddp << " " << evenp << " " << oddq << " " << evenq << endl;
        printf("%lld\n", 1LL*oddp*oddq + 1LL*evenp*evenq);
    }
    return 0;
}


/*
4
3 0
0 0 0
*/
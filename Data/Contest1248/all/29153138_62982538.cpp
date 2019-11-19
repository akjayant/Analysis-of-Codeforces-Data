#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <ctime>
#include <cstdlib>
using namespace std;


typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 19930726;
const double eps = 1e-5;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    //freopen("result.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        ll ans = 0;
        scanf("%d", &n);
        ll odda = 0, evena = 0;
        ll oddb = 0, evenb = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if(a[i] & 1) odda++;
            else evena++;
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
            if(b[i] & 1) oddb++;
            else evenb++;
        }
        ans += odda * oddb;
        ans += evena * evenb;
        printf("%lld\n", ans);
    }
    return 0;
}
/*

*/

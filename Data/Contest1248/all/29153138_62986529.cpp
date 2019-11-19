//#include <bits/stdc++.h>
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


int n;
ll a[maxn];

int main() {
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum += a[i];
    sort(a + 1, a + 1 + n);
    ll x = 0;
    for(int i = 1; i <= n/2; i++) x += a[i];
    ll y = sum - x;
    ll ans = x*x + y*y;
    printf("%lld\n", ans);
    return 0;
}
/*

*/

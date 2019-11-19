#include <cstring>
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX (100005)
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define int long long
#define ll long long
#define lson (p<<1)
#define rson (lson | 1)
#define ALL(x) x.begin(),x.end()

const long long mod = 1e9 + 7;

int p[MAX];
int q[MAX];

signed main(void)
{
   int t; cin >> t;
   while(t--){
        int n;
        scanf("%lld", &n);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", p + i);
            if(p[i]%2) cnt1++;
        }
        int m;
        scanf("%lld", &m);
        for(int i = 1; i <= m; i++){
            scanf("%lld", q + i);
            if(q[i] % 2) cnt2++;
        }
        cout <<   cnt1 * (cnt2) + (n - cnt1) * (m - cnt2) << endl;
   }
}

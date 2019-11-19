// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <assert.h>
#include <cmath>
#include <ctime>
using namespace std;
#define me(x,y) memset((x),(y),sizeof (x))
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define SGN(x) ((x)>0?1:((x)<0?-1:0))
#define ABS(x) ((x)>0?(x):-(x))                                                                                                                                                     
// #define int __int128
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxn = 1e5+100;
const int inf = __INT32_MAX__;
const ll INF = __LONG_LONG_MAX__;
const ll MOD = 1e9+7;
const double eps = 1e-10;
const double PI = std::acos(-1);

ll a[maxn];
ll sum[maxn];
int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("1in.in","r",stdin);
    freopen("1out.out","w",stdout);
#endif
    int n,m;
    while(cin>>n>>m){
        if(n < m) swap(n,m);
        a[0]=2,a[1] = 2,a[2] = 4;
        sum[0]=0,sum[1] = 2,sum[2] = 4;
        for(int i = 3; i <= n; ++i) a[i] = (a[i-1]+a[i-2])%MOD,sum[i] = (sum[i-1]+a[i-1])%MOD;
        // cout<<a[4]<<" "<<sum[3]<<endl;
        cout<<(a[n]+sum[m-1])%MOD<<endl;
    }
    
    return 0;
}
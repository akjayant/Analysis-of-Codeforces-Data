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
const ll MOD = 998244353;
const double eps = 1e-10;
const double PI = std::acos(-1);


int a[maxn];
int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("1in.in","r",stdin);
    freopen("1out.out","w",stdout);
#endif
    int n;
    cin>>n;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    sort(a+1,a+n+1);
    ll sum1=0,sum2=0;
    for(int i = 1; i <= n; ++i){
        if(i>n/2) sum2+=1ll*a[i];
        else sum1+=1ll*a[i];
    }
    cout<<(sum1*sum1+sum2*sum2)<<endl;
    return 0;
}
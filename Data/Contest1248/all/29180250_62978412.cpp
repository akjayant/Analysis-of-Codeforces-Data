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
 
const int maxn = 1100;
const int inf = __INT32_MAX__;
const ll INF = __LONG_LONG_MAX__;
const ll MOD = 998244353;
const double eps = 1e-10;
const double PI = std::acos(-1);



int main(){
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("1in.in","r",stdin);
    freopen("1out.out","w",stdout);
#endif
    int t;cin>>t;
    while(t--){
        int n,m,p,q;
        ll pe=0,po=0,qe=0,qo=0;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>p;
            if(p<0) p=-p;
            if(p&1) pe++;
            else po++;
        }
        cin>>m;
        for(int i = 1; i <= m; ++i){
            cin>>q;
            if(q<0) q=-q;
            if(q&1) qe++;
            else qo++;
        }
        cout<<qe*pe+qo*po<<endl;
    }
    return 0;
}
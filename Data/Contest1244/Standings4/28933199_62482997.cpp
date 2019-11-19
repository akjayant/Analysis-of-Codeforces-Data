#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <math.h>

using namespace std;

#define x first
#define y second
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define all(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < b; i++)
#define per(i, a, b) for(int i = b-1; i >= a; i--)
#define DBG(x) cerr << (#x) << "=" << x << "\n";
#define ll long long
#define inf 1000000007
#define mod 1000000007
#define N 100001

template<typename U, typename V> void Min(U &a, const V & b){if(a > b)a = b;}
template<typename U, typename V> void Max(U &a, const V & b){if(a < b)a = b;}
template<typename U, typename V> void add(U &a, const V & b){a = (a + b) % mod;}
template<typename U> U gcd(U a, U b){
    if(a == 0)return b;
    if(b == 0)return a;
    if(a >= b)return gcd(a % b, b);
    else return gcd(a, b % a);
}
int pow(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1)ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

vi g[N];
int a[3][N], q[N], c[N];
int main(){
    int T, i, j, k, m, K, n;
    scanf("%d", &n);
    rep(i, 0, 3){
        rep(j, 0, n)scanf("%d", &a[i][j]);
    }
    rep(i, 1, n){
        scanf("%d%d", &j, &k);
        j--, k--;
        g[j].pb(k), g[k].pb(j);
    }
    rep(i, 0, n)if(SZ(g[i]) >= 3){
        puts("-1");
        return 0;
    }
    int rt, sz = 0;
    rep(i, 0, n)if(SZ(g[i]) == 1){rt = i;break;}
    q[sz++] = rt;
    rep(i, 0, n-1){
        k = q[i];
        for(auto &v : g[k])if(v != rt){
            q[sz++] = v;
            break;
        }
        rt = k;
    }
    ll ans = -1;
    pii res;
    rep(i, 0, 3){
        rep(j, 0, 3)if(j != i){
            int x = i, y = j;
            ll s = a[x][q[0]] + a[y][q[1]];
            rep(k, 2, sz){
                int z = 3 - x - y;
                s += a[z][q[k]];
                x = y, y = z;
            }
            if(ans < 0 || ans > s){
                ans = s;
                res = {i, j};
            }
        }
    }
    printf("%lld\n", ans);
    int x = res.x, y = res.y;
    c[q[0]] = x;
    c[q[1]] = y;
    rep(i, 2, sz){
        int z = 3 - x - y;
        c[q[i]] = z;
        x = y, y = z;
    }
    rep(i, 0, n)printf("%d ", c[i] + 1);
    puts("");
}

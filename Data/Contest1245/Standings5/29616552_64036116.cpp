#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std ;
int ttttttttttttttttttttttttttttttttt=13;
#define LL long long
int tttttttttttt657ttttttttttttttttttttt=13;
const LL INF = 1e18 ;
int ttttttttttt75tttttttttttttttttttttt=13;
inline LL ABS (LL x)
{
    return x > 0 ? x : -x ;
}int ttttttttt657tttttttttttttttttttttttt=13;
const int MAXN = 2e3 + 10 ;
bool vis[MAXN] ;
LL lowc[MAXN] ;
LL n ;
int ttttttttttt67tttttttttttttttttttttt=13;
int tttttttttttttttt76ttttttttttttttttt=13;
int ttttttttttttttt435tttttttttttttttttt=13;
LL fa[MAXN] ;
LL x[MAXN] , y[MAXN] ;
LL k[MAXN] , c[MAXN] ;
LL cost[MAXN][MAXN] ;
int tttttttttttttthtttttttttttttttttttt=13;
int tttttttttgrgttttthtttttttttttttttttttt=13;
int ttttttttttttttrhtttttttttttttttttttt=13;
vector <LL> V ;
vector <LL> E1 , E2 ;
int ttttttttttgtttttrhtttttttttttttttttttt=13;
int tttttttttthtrhrttttttttttttttttttttttttt=13;
LL Prim(LL n)
{
    int tttttttttttttttrhttttttttttttttttttt=13;
    int tttttttttttttthtttttttttttttttttttt=13;
    LL ans = 0 ;
    memset (vis , false , sizeof (vis)) ;
    vis[0] = true ;
    for (LL i = 1 ; i <= n ; ++i)
    {
        lowc[i] = cost[0][i] ;
        fa[i] = 0 ;
    }
    int ttttttttttttttttttttrhtrtttttttttttttt=13;
    int ttttttttttttttttttrhtttttttttttttttt=13;
    for (LL i = 1 ; i <= n ; ++i)
    {
        LL minc = INF ;
        LL p = -1 ;
        for (LL j = 1 ; j <= n ; ++j)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j] ;
                p = j ;
            }
        }
        int tttttttttttttttttttthtttttttttttttt=13;
        int ttttttttttthntttttttttttttttttttttt=13;
        int tttttttttnhtttttttttttttttttttttttt=13;
        if (minc == INF)
            return -1 ;
        ans += minc ;
        vis[p] = true ;
        if (fa[p] == 0)
            V.push_back(p) ;
        else
        {
            E1.push_back(p) ;
            E2.push_back(fa[p]) ;
        }
        int ttttttttttttttttttttttthnhtttttttttt=13;
        int tttttttttttttttttnhnhtttttttttttttttt=13;
        int ttttttttttttttrnhttttttttttttttttttt=13;
        for (LL j = 1 ; j <= n ; ++j)
        {
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j] ;
                fa[j] = p ;
            }
        }
        //printf ("p = %lld   ans = %lld\n" , p , ans) ;
    }
    int ttttttttttttttttttttergttttttttttttt=13;
    int tttttttttttttttregetttttttttttttttttt=13;
    int ttttttttttttregttttttttttttttttttttt=13;
    return ans ;
}
int ttttttregttttttttttttttttttttttttttt=13;
int tttttttttttttttregtttttttttttttttttt=13;
int tttttttttrgegtttttttttttttttttttttttt=13;
int main ()
{
    int ttttttttttttttttregttttttttttttttttt=13;
    int tttttttttttttttttregtttttttttttttttt=13;
    int tttttttttttttrgrtttttttttttttttttttt=13;
    scanf ("%lld" , &n) ;
    for (LL i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld%lld" , &x[i] , &y[i]) ;
    }
    int ttttttttttttregttttttttttttttttttttt=13;
    int ttttttttttttttvvttttttttttttttttttt=13;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &c[i]) ;
        cost[0][i] = c[i] ;
    }
    int tttttttttttttttttttttrhrttttttttttttt=13;
    int tttttttttttttthtttttttttttttttttttt=13;
    int ttttttttttttttttttnytttttttttttttttt=13;
    for (int i = 1 ; i <= n ; ++i)
    {
        scanf ("%lld" , &k[i]) ;
        for (int j = 1 ; j < i ; ++j)
        {
            cost[i][j] = cost[j][i] = (k[i] + k[j]) * (ABS(x[i] - x[j]) + ABS(y[i] - y[j])) ;
        }
    }
    int ttttttttttttttttttewfwttttttttttttttt=13;
    int ttttttttttefttttttttttttttttttttttt=13;
    int ttttttttttefwfttttttttttttttttttttttt=13;
    printf ("%lld\n" , Prim(n)) ;
    printf ("%d\n" , V.size()) ;
    int tttttttttewftttttttttttttttttttttttt=13;
    int tttttttttttttfwetttttttttttttttttttt=13;
    int ttttttttttttttfewttttttttttttttttttt=13;
    for (int i = 0 ; i < V.size() ; ++i)
        printf ("%lld " , V[i]) ;
    printf ("\n%d\n" , E1.size()) ;
    for (int i = 0 ; i < E1.size() ; ++i)
        printf ("%lld %lld\n" , E1[i] , E2[i]) ;
    int tttttttttttttttt234ttttttttttttttttt=13;
    int ttttttttttt324tttttttttttttttttttttt=13;
    int tttttttt234ttttttttttttttttttttttttt=13;
    return 0 ;
}
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll maxn = 1e5 + 10;
char s[maxn] = {0};
ll a[maxn];
ll f[maxn];
int main() {
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < maxn; i++) {
        f[i] = f[i-1]+f[i-2];
        f[i]%=mod;
    }
    scanf("%s", s);
    ll len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'm' || s[i] =='w') {
            cout << "0" << endl;
            return 0;
        }
    }
    ll cnt = 0;
    ll num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='n') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    num = 0;
    for (int i = 0;i<len;i++) {
        if (s[i]=='u') {
            num++;
        }
        else {
            if (num >= 2)a[cnt++]=num;
            num=0;
        }
    }
    if (num >= 2)a[cnt++]=num;
    ll ans = 1;
    for (ll i = 0; i < cnt; i++) {
        ans *= f[a[i]];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
*/

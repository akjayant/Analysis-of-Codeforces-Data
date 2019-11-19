#include<bits/stdc++.h>
#include <cstring>
#include <iostream>
#define pie acos(-1)
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define slll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define ss(st) scanf("%s",st)
#define sch(ch) scanf("%ch",&ch)
#define ps(a) printf("%s",a)
#define newLine() printf("\n")
#define pi(a) printf("%d",a)
#define pii(a,b) printf("%d %d",a,b)
#define piii(a,b,c) printf("%d %d %d",a,b,c)
#define pl(a) printf("%lld",a)
#define pll(a,b) printf("%lld %lld",a,b)
#define plll(a,b,c) printf("%lld %lld %lld",a,b,c)
#define pd(a) printf("%lf",a)
#define pdd(a,b) printf("%lf %lf",a,b)
#define pddd(a,b,c) printf("%lf %lf %lf",a,b,c)
#define pch(c) printf("%ch",c)
#define debug1(str,a) printf("%s=%d\n",str,a)
#define debug2(str1,str2,a,b) printf("%s=%d %s=%d\n",str1,a,str2,b)
#define debug3(str1,str2,str3,a,b,c) printf("%s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c)
#define debug4(str1,str2,str3,str4,a,b,c,d) printf("%s=%d %s=%d %s=%d %s=%d\n",str1,a,str2,b,str3,c,str4,d)
#define for0(i,n) for(i=0;i<n;i++)
#define for1(i,n) for(i=1;i<=n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define forstl(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define nl puts("")
#define sd(a) scanf("%lf",&a)
#define sdd(a,b) scanf("%lf %lf",&a,&b)
#define sddd(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sp printf(" ")
#define ll long long int
#define ull unsigned long long int
#define MOD 1000000007
#define mpr make_pair
#define pub(x) push_back(x)
#define pob(x) pop_back(x)
#define mem(ara,value) memset(ara,value,sizeof(ara))
#define INF INT_MAX
#define eps 1e-9
#define checkbit(n, pos) (n & (1<<pos))
#define setbit(n, pos) (n  (1<<pos))
#define para(i,a,b,ara)\
for(i=a;i<=b;i++){\
    if(i!=0){printf(" ");}\
    cout<<ara[i];\
}\
printf("\n");
#define pvec(i,vec)\
for(i=0;i<vec.size();i++){\
    if(i!=0){printf(" ");}\
    cout<<vec[i];\
}\
printf("\n");
#define ppara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    for(j=0;j<m;j++){\
        if(j!=0){printf(" ");}\
        cout<<ara[i][j];\
    }\
    printf("\n");\
}
#define ppstructara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j];printf("\n");\
    }\
}
#define ppvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        if(j!=0){printf(" ");}\
        cout<<vec[i][j];\
    }\
    printf("\n");\
}
#define ppstructvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j];printf("\n");\
    }\
}
#define sara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    scanf("%d",&ara[i]);\
}
#define pstructara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i];nl;\
}
#define pstructvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i];nl;\
}
#define pstructstl(stl,x)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    x=*it;\
    cout<<x;nl;\
}\
nl;
#define pstl(stl)\
for(__typeof(stl.begin()) it=stl.begin();it!=stl.end();++it){\
    if(it!=stl.begin()){sp;}\
    pi(*it);\
}\
nl;
#define ppairvec(i,vec)\
for(i=0;i<vec.size();i++){\
    cout<<vec[i].first;sp;cout<<vec[i].second;printf("\n");\
}
#define ppairara(i,a,b,ara)\
for(i=a;i<=b;i++){\
    cout<<ara[i].first;sp;cout<<ara[i].second;printf("\n");\
}
#define pppairvec(i,j,n,vec)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<vec[i].size();j++){\
        cout<<vec[i][j].first;sp;cout<<vec[i][j].second;nl;\
    }\
}
#define pppairara(i,j,n,m,ara)\
for(i=0;i<n;i++){\
    printf("%d:\n",i);\
    for(j=0;j<m;j++){\
        cout<<ara[i][j].first;printf(" ");cout<<ara[i][j].second;nl;\
    }\
}
#define SZ 2 * 100010
using namespace std;
//bool status[100010];
//vector <int> prime;
//void siv(){
//    int N = 100005, i, j; prime.clear();
//    int sq = sqrt(N);
//    for(i = 4; i <= N; i += 2){ status[i] = true; }
//    for(i = 3; i <= sq; i+= 2){
//        if(status[i] == false){
//            for(j = i * i; j <= N; j += i){ status[j] = true; }
//        }
//    }
//    status[1] = true;
//    for1(i, N){ if(!status[i]){ prime.pub(i); } }
//}
int add(int _a, int _b){
   _a = (_a + MOD) % MOD;
   _b = (_b + MOD) % MOD;
   return (_a + _b) % MOD;
}
int mul(int _a, int _b){
   _a = (_a + MOD) % MOD;
   _b = (_b + MOD) % MOD;
   return ((ll)((ll)_a * (ll)_b)) % MOD;
}
ll l, r, x, y, dp[50][2][50][2];
bool vis[50][2][50][2];
void input(){
    ll i, j;
    sll(l, r);
}
ll F(ll posx, bool sx, ll posy, bool sy){
    if(posx == -1){ return 1; }
    if(vis[posx][sx][posy][sy]){ return dp[posx][sx][posy][sy]; }
    vis[posx][sx][posy][sy] = true;
    ll ret = 0, a, b;
    a = x & (1ll << posx);
    b = y & (1ll << posy);
    if(!sx && !sy){
        if(a > 0 && b > 0){
            ret = ret + F(posx - 1, true, posy - 1, true);
            ret = ret + F(posx - 1, true, posy - 1, false);
            ret = ret + F(posx - 1, false, posy - 1, true);
        }
        else if(a > 0){
            ret = ret + F(posx - 1, true, posy - 1, false);
            ret = ret + F(posx - 1, false, posy - 1, false);
        }
        else if(b > 0){
            ret = ret + F(posx - 1, false, posy - 1, true);
            ret = ret + F(posx - 1, false, posy - 1, false);
        }
        else{
            ret = ret + F(posx - 1, false, posy - 1, false);
        }
    }
    else if(sx && !sy){
        if(b > 0){
            ret = ret + F(posx - 1, true, posy - 1, true);
            ret = ret + F(posx - 1, true, posy - 1, false);
            ret = ret + F(posx - 1, true, posy - 1, true);
        }
        else{
            ret = ret + F(posx - 1, true, posy - 1, false);
            ret = ret + F(posx - 1, true, posy - 1, false);
        }
    }
    else if(sy && !sx){
        if(a > 0){
            ret = ret + F(posx - 1, true, posy - 1, true);
            ret = ret + F(posx - 1, true, posy - 1, true);
            ret = ret + F(posx - 1, false, posy - 1, true);
        }
        else{
            ret = ret + F(posx - 1, false, posy - 1, true);
            ret = ret + F(posx - 1, false, posy - 1, true);
        }
    }
    else{
        ret = ret + 3 * F(posx - 1, true, posy - 1, true);
    }
    return dp[posx][sx][posy][sy] = ret;
}
void solve(){
    ll i, j, a, b, c, d;
    x = l - 1, y = l - 1;
    if(x < 0 || y < 0){ a = 0; }
    else{
        mem(vis, false);
        a = F(35, false, 35, false);
    }
    x = l - 1, y = r;
    if(x < 0 || y < 0){ b = 0; }
    else{
        mem(vis, false);
        b = F(35, false, 35, false);
    }
    x = r, y = l - 1;
    if(x < 0 || y < 0){ c = 0; }
    else{
        mem(vis, false);
        c = F(35, false, 35, false);
    }
    x = r, y = r;
    if(x < 0 || y < 0){ d = 0; }
    else{
        mem(vis, false);
        d = F(35, false, 35, false);
    }
//    pl(d); nl;
//    plll(a, b, c), sp, pl(d); nl;
    ll ans = d - b - c + a;
    pl(ans); nl;
}
int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt", "w", stdout);
    int cs, ts;
    si(ts);
    for0(cs, ts){
        input();
        solve();
    }
}

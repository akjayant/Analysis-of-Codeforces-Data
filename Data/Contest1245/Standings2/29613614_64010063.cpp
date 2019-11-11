/*
    Written by Nitrogens
    Desire for getting accepted!!
*/
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <stack>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int maxn = 1e5+5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const db PI = acos(-1);
const db ERR = 1e-10;

#define Se second
#define Fi first
#define pb push_back
#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl

char s[maxn];
long long Fac[maxn],Inv[maxn],inv[maxn];
void init()
{
    Fac[0]=Inv[0]=Fac[1]=Inv[1]=inv[1]=1;
    for(int i=2;i<maxn;i++)
    {
        Fac[i]=Fac[i-1]*i%Mod;
        inv[i]=inv[Mod%i]*(Mod-Mod/i)%Mod;
        Inv[i]=Inv[i-1]*inv[i]%Mod;
    }
}
long long c(int n,int m)
{
    if(n<m||m<0) return 0;
    return Fac[n]*Inv[m]%Mod*Inv[n-m]%Mod;
}
long long C(int n,int m)
{
    int ans=1;
    while(n||m) ans=ans*c(n%Mod,m%Mod)%Mod,n/=Mod,m/=Mod;
    return ans;
}

ll solve(int n) {
    int range = n / 2;
    ll res = 0;
    for (int i = 0; i <= range; i++) {
        res = (res + c(n - i, i)) % Mod;
    }
    return res;
}

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);

    int n;
    init();
    scanf("%s", s + 1);
    n = strlen(s + 1);

    int len = 1;
    ll ans = 1;
    bool mark = 0;
    for (int i = 1; i <= n; i++) {
        mark |= (s[i] == 'w' || s[i] == 'm');
    }
    for (int i = 2; i <= n + 1; i++) {
        if (s[i] == s[i - 1]) len++;
        else {
            if (s[i - 1] == 'n' || s[i - 1] == 'u') {
                ans = (ans * solve(len)) % Mod;
            }
            len = 1;
        }
    }
    if (mark) ans = 0;
    printf("%lld\n", ans);

    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}

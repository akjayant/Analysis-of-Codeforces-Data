#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <ctime>
#define ll long long
#define ld double
#define lson rt << 1, l, m
#define pi acos(-1)
#define rson rt << 1 | 1, m + 1, r
#define fo(i, l, r) for (int i = l; i <= r; i++)
#define fd(i, l, r) for (int i = r; i >= l; i--)
#define mem(x) memset(x, 0, sizeof(x))
#define eps 1e-7
using namespace std;
const ll maxn = 100050;
const ll mod = 998244353;
ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    };
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    };
    return x * f;
}
int n;
ll a[maxn];
int main()
{
    n=read();
    fo(i,1,n){
        a[i]=read();
    }
    ll w=0,h=0;
    sort(a+1,a+1+n);
    int lp=1,rp=n;
    while(lp<rp){
        w+= a[lp];
        h+=a[rp];
        lp++;rp--;
    }
    ll ans = 0;
    if(lp==rp){
        ans = max((w+a[lp])*(w+a[lp])+h*h,ans);
        ans = max((h+a[lp])*(h+a[lp])+w*w,ans);
    }else{
        ans = max(w*w+h*h,ans);
    }
    cout<<ans;
    return 0;
}
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
const ll mod = 1000000007;
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
int n,m;
ll tot[maxn],sum[maxn];
int main()
{
    sum[1]=sum[2]=2;
    for(int i=3;i<=100005;i++){
        sum[i] = (sum[i-1] + sum[i-2]) % mod;
    }
    cin>>n>>m;
    if(n==1){
        cout<<sum[m+1];
    }else if(m==1){
        cout<<sum[n+1];
    }else{
        ll t1 = sum[m+1];
        fo(i,2,n){
            t1 += sum[i-1];
            t1 %= mod;
        }
        cout<<t1;
    }
    return 0;
}
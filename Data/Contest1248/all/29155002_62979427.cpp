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
const ll maxn = 4050;
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
int main()
{
    int T=read();
    ll n,m;
    ll a,b,c,d,t;
    while(T--){
        a=b=c=d=0;
        n=read();
        
        fo(i,1,n){
            t=read();
            if(t&1)a++;
            else b++;
        }m=read();
        fo(i,1,m){
            t=read();
            if(t&1)c++;
            else d++;
        }
        //cout<<"??"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        cout<<a*c+b*d<<endl;
    }
    return 0;
}
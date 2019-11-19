#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
typedef long long ll;
const int Mod = 1e9 + 7;
using namespace std;
struct node
{
    ll a[4][4];
    node mul(node x)
    {
        node ans;
        for(int i = 0;i < 4; i++)
            for(int j = 0;j < 4; j++)
            {
                ans.a[i][j] = 0;
                for(int k = 0;k < 4; k++)
                {
                    ans.a[i][j] = (ans.a[i][j] % Mod + a[i][k] * x.a[k][j] % Mod + Mod) % Mod;
                }
            }
        return ans;
    }
};
node multi(node a,int b)
{
    node ans;
    memset(ans.a,0,sizeof(ans.a));
    for(int i=0; i < 4; i++) ans.a[i][i] = 1;
    while(b)
    {
        if(b&1) ans = ans.mul(a);
        a = a.mul(a);
        b >>= 1;
    }
    return ans;
}
int n,m;
int main()
{
    cin >> n >> m;
    node tmp;
    memset(tmp.a, 0, sizeof(tmp.a));
    tmp.a[0][2] = 1;
    tmp.a[1][0] = tmp.a[1][2]=1;
    tmp.a[2][1] = tmp.a[2][3]=1;
    tmp.a[3][1] = 1;
    node A = tmp;
    ll ans = 0;
    if(n>=3)
    {
        node res = multi(A,n-2);
        for(int i=0; i<4; i++)
        {
            for(int j = 0;j < 4; j++)
            {
                ans = (ans + res.a[i][j] + Mod) % Mod;
            }
        }
    }
    else
    {
        if(n == 1) ans+=2;
        else ans += 4;
    }
    A = tmp;
    if(m >= 3)
    {
        node res = multi(A, m-2);
        for(int i = 0;i < 4; i++)
        {
            for(int j = 0;j < 4; j++)
            {
                ans = (ans + res.a[i][j] + Mod) % Mod;;

            }
        }
    }
    else
    {
        if(m == 1) ans += 2;
        if(m == 2) ans += 4;
    }
    ans = (ans - 2 + Mod) % Mod;
    printf("%lld\n", ans);
    return 0;
}

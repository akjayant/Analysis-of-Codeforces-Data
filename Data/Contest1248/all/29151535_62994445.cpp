#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdlib>
#define pi 3.14159265
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll mod = 1000000000 + 7;
const double kd = 1.41421356237;

ll was[100500],n,m;
ll din(ll pos, ll n)
{
    if(pos == n + 1)
        return 1;
    if(pos == n + 2)
        return 0;
    if(was[pos] != -1)
        return was[pos];
    ll an = (din(pos + 1,n) % mod) +  (din(pos + 2,n) % mod);
    was[pos] = an % mod;
    return an % mod;
}
int main()
{
    //freopen("ladder.in ","r",stdin);
    //freopen("ladder.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        was[i] = -1;
    ll an1 = ((din(1,n)-1) * 2) % mod;
    for(int i=0;i<=m;i++)
        was[i] = -1;
    ll an2 = (din(1,m) * 2) % mod;
    cout<<(an1 + an2) % mod;
}


#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
# include <math.h>
#define lli long long int
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;

lli modexp(lli a,lli n)
{
    lli r=1;
    while(n){
        if(n&1)
            r=(r*a)%mod;
        a=(a*a)%mod;
        n>>=1;
    }
    return r;
}


void solve()
{
    lli n, m;
    cin>>n>>m;
    lli ans = modexp(2, m);
    ans --;
    ans = modexp(ans, n);
    cout<<ans<<endl;
    return ;
}
/*
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}

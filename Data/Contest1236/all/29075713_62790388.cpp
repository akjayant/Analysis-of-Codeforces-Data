/*************************************************************************
	> File Name: 2019_10_17_2.cpp
	> Author: z472421519
	> Mail: 
	> Created Time: 2019年10月17日 星期四 21时47分24秒
 ************************************************************************/

#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#define ll long long
const ll mod = 1e9 + 7;
using namespace std;

ll quick_pow(ll a,ll n)
{
    ll res = 1ll;
    while(n)
    {
        if(n & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll n,m;
    cin >> n >> m;
    cout << quick_pow(quick_pow(2ll,m) - 1,n);

    return 0;
}

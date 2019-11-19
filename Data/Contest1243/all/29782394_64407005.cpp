//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#define ll  long long
using namespace std;
const int MAX = 1000;//100000
const int MAX_1 = 1000100;
const int MAX_2 = 1000010;
const int INF = 0x3f3f3f3f;//1061109567,1e9,int-MAX2147483647;
const double EPS = 0.0000001;
const int MOD = 998244353;//998244353;
const double PI = acos(-1);
//void runtime(){cout << "The run time is:" << (double)clock() /CLOCKS_PER_SEC<< "s" << endl;}
ll T,N,M,K,D;

/* --------------------------------------------------------------------------------------------------*/

/* --------------------------------------------------------------------------------------------------*/

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
/* -----------------------------------------------------------------------------------------*/
    cin >> N;
    ll u = N;
    if(u == 1) cout << 1 <<endl;
    else if ( u == 2) cout << 2 <<endl;
    else
    {
        bool flag = true;
        ll ans = u;
        for(ll i=2; i*i <= u ; i++)
        {
            if(u % i == 0)
            {
                ll k = u;
                while(k % i == 0)
                {
                    k /= i;
                    if(k == 1) break;
                }
                if(k == 1)
                {
                    ans = i;
                    break;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << ans << endl;
        else cout << 1 << endl;
    }

    return 0;
}


// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

#define USE_IOSTREAM \
{\
	ios::sync_with_stdio(false);\
	cin.tie(0);\
	cout.tie(0);\
}

#define pii pair<int, int>
#define mp make_pair

typedef long long ll;

#define FAIL_RETURN \
do\
{\
    printf("-1\n");\
    return 0;\
} while(0);


const ll MOD = 1e9 + 7;
ll mypower(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}


int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ans = (mypower(2, m) - 1 + MOD) % MOD;
    ans = mypower(ans, n);
    cout << ans << endl;
	
	
	return 0;
}

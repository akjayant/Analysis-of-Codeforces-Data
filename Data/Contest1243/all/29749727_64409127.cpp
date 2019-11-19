// include stdc++.h slows down compilation much.
//#include<bits/stdc++.h>
#include <deque>
#include <assert.h>
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


int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
    ll a, org;
    cin >> a;
    org = a;
    int cnt = 0;
    ll factor = 0;
    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt++;
            factor = i;
            while (a % i == 0)
            {
                a /= i;
            }
        }
    }

    if (a != 1 && a < org)
    {
        cnt++;
    }

    ll ans = 0;
    if (cnt == 0)
    {
        ans = org;
    }
    else if (cnt == 1)
    {
        ans = factor;
    }
    else
    {
        ans = 1;
    }
    cout << ans << endl;
	
	return 0;
}

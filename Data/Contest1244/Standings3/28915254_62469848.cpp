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

int solve()
{
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    int x, y;
    for (x = 1; x < k; x++)
    {
        y = k - x;

        if (x * c >= a && y * d >= b)
        {
            break;
        }
    }

    if (x == k)
    {
        FAIL_RETURN;
    }

    cout << x << " " << y << endl;
    return 0;
}
int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
	
	return 0;
}

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

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while (b >= 1 && c >= 2)
    {
        ans += 3;
        b -= 1;
        c -= 2;
    }

    while (a >= 1 && b >= 2)
    {
        ans += 3;
        b -= 2;
        a -= 1;
    }

    cout << ans << endl;
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

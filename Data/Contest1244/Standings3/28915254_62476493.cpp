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

char a[1005];

void solve()
{
    int n;
    scanf("%d", &n);
    scanf("%s", a);

    int minIdx = n, maxIdx = -1;
    bool has1 = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            minIdx = min(minIdx, i);
            maxIdx = max(maxIdx, i);
            has1 = true;
        }
    }

    if (!has1)
    {
        printf("%d\n", n);
        return;
    }

    int num = min(minIdx, n - maxIdx - 1);
    int ans = 2 * (n - num);
    printf("%d\n", ans);
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif

    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
	
	
	return 0;
}

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

const int N = 1005;
int c[N];
int sum[N];

void solve()
{
    int n;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        c[a]++;
    }

    sum[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1] + c[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = min(i, sum[i]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

int main()
{
	USE_IOSTREAM;
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

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

ll MOD = 1e9 + 7;
const int N = 1e5 + 7;

char s[N];
ll dp[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif

    int n;
    scanf("%s", s);
    n = strlen(s);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            printf("0\n");
            return 0;
        }
    }

    ll ans = 1;
    int j;
    for (int i = 0; i < n; i = j)
    {
        for (j = i + 1; j < n && s[j] == s[j - 1] && (s[j] == 'n' || s[j] == 'u'); j++);
        int len = j - i;
        ans = ans * dp[len] % MOD;
    }
    printf("%lld\n", ans);
	
	
	return 0;
}

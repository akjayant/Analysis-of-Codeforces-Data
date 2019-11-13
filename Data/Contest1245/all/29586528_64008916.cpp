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


void solve()
{
    char s[105];
    char t[105];
    memset(s, 0, sizeof(s));
    memset(t, 0, sizeof(t));

    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    scanf("%s", s);
    int aa, bb, cc;
    aa = bb = cc = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            aa++;
        }
        else if (s[i] == 'P')
        {
            bb++;
        }
        else
        {
            cc++;
        }
    }

    int ca = min(a, cc);
    int cb = min(b, aa);
    int gc = min(c, bb);
    int ans = ca + cb + gc;
    if (ans * 2 < n)
    {
        printf("NO\n");
        return;
    }

    multiset<char> S;
    for (int i = 0; i < a - ca; i++)
    {
        S.insert('R');
    }
    for (int i = 0; i < b - cb; i++)
    {
        S.insert('P');
    }
    for (int i = 0; i < c - gc; i++)
    {
        S.insert('S');
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S' && ca)
        {
            t[i] = 'R';
            ca--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R' && cb)
        {
            t[i] = 'P';
            cb--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P' && gc)
        {
            t[i] = 'S';
            gc--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!t[i])
        {
            t[i] = *S.begin();
            S.erase(S.begin());
        }
    }

    printf("YES\n");
    printf("%s\n", t);
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

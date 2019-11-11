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

inline ll gcd(ll a, ll b)
{
	ll c;
	while (b)
	{
		c = b;
		b = a % b;
		a = c;
	}
	return a;
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
        int a, b;
        scanf("%d%d", &a, &b);
        ll c = gcd(a, b);
        if (c != 1)
        {
            printf("Infinite\n");
        }
        else
        {
            printf("Finite\n");
        }
    }
	
	
	return 0;
}

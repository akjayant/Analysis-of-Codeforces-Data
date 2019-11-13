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

int a[303][303];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            for (int j =  1; j <= n; j++)
            {
                a[j][i] = (i - 1) * n + j;
            }
        }
        else
        {
            for (int j = n; j >= 1; j--)
            {
                a[j][i] = (i - 1) * n + (n + 1 - j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
	
	
	return 0;
}

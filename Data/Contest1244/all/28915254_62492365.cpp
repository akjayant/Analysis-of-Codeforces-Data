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


const int N = 1e5 + 5;
vector<int> graph[N];
ll c[N][3];
ll dp[N][3][3];
int a[N];

void dfs(int u, int pre)
{
    int idx = 0;
    for (auto v : graph[u])
    {
        if (v == pre)
        {
            continue;
        }

        dfs(v, u);
        idx = v;
    }


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (idx == 0)
            {
                dp[u][i][j] = c[u][i];
            }
            else
            {
                int k = 0;
                for (k = 0; k < 3; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    break;
                }
                dp[u][i][j] = c[u][i] + dp[idx][j][k];
            }
        }
    }
}

void dfsPaint(int u, int pre, int c1, int c2)
{
    a[u] = c1;
    int idx = 0;
    for (auto v : graph[u])
    {
        if (v == pre)
        {
            continue;
        }

        idx = v;
    }

    if (idx == 0)
    {
        return;
    }

    int c3 = 0;
    for (c3 = 0; c3 < 3; c3++)
    {
        if (c3 == c1 || c3 == c2)
        {
            continue;
        }
        break;
    }

    dfsPaint(idx, u, c2, c3);
}

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	#endif

    int n;
    scanf("%d", &n);
    fill_n((ll*)dp, N * 3 * 3, (ll)1e17);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld", &c[j][i]);
        }
    }

    int u, v;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((int)graph[i].size() > 2)
        {
            FAIL_RETURN;
        }
        else if ((int)graph[i].size() == 1)
        {
            root = i;
        }
    }

    dfs(root, 0);

    ll ans = 1e18;
    pii minColor;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                continue;
            }

            if (ans > dp[root][i][j])
            {
                ans = dp[root][i][j];
                minColor = mp(i, j);
            }
        }
    }

    dfsPaint(root, 0, minColor.first, minColor.second);
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i] + 1);
    }
    printf("\n");

	
	
	return 0;
}

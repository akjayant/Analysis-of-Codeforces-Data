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

const int N = 1e5 + 10;
set<int> graph[N];
int mark[N];

int main()
{
	// USE_IOSTREAM;
	#ifndef ONLINE_JUDGE
	//freopen("1.txt", "r", stdin);
	#endif
	
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int ans = 0;
    set<int> S[2];
    mark[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (graph[1].find(i) == graph[1].end())
        {
            S[0].insert(i);
        }
        else
        {
            S[1].insert(i);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (!S[0].empty())
        {
            u = *S[0].begin();
            S[0].erase(S[0].begin());
            vector<int> vec;
            for (auto v : S[1])
            {
                if (graph[u].find(v) == graph[u].end())
                {
                    vec.push_back(v);
                    S[0].insert(v);
                }
            }
            for (auto v : vec)
            {
                S[1].erase(v);
            }
        }
        else
        {
            u = *S[1].begin();
            S[1].erase(S[1].begin());
            ans++;
            vector<int> vec;
            for (auto v : S[1])
            {
                if (graph[u].find(v) == graph[u].end())
                {
                    vec.push_back(v);
                    S[0].insert(v);
                }
            }
            for (auto v : vec)
            {
                S[1].erase(v);
            }
        }
    }

    printf("%d\n", ans);
	
	return 0;
}

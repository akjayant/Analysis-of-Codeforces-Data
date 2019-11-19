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


struct Node
{
    Node(){}
    Node(ll d, int idx, int type, int preIdx = 0)
    {
        this->d = d;
        this->idx = idx;
        this->type = type;
        this->preIdx = preIdx;
    }

    bool operator < (const Node &other) const
    {
        if (d != other.d)
        {
            return d < other.d;
        }
        if (idx != other.idx)
        {
            return idx < other.idx;
        }
        if (type != other.type)
        {
            return type < other.type;
        }
        return false;
    }
    ll d;
    int idx;
    int type;
    int preIdx;
};


const int N = 2005;
ll d[N];
ll dp[N];
ll dist[N][N];
ll X[N];
ll Y[N];
ll c[N];
ll k[N];
int mark[N];


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
        scanf("%d%d", &X[i], &Y[i]);
    }
    ll minK = 1e15;
    int minIdx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        if (c[i] < minK)
        {
            minK = c[i];
            minIdx = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                dist[i][j] = (abs(X[i] - X[j]) + abs(Y[i] - Y[j])) * (k[i] + k[j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != minIdx)
        {
            d[i] = dist[minIdx][i];
        }
    }

    ll ans = minK;
    vector<int> ansV;
    ansV.push_back(minIdx);
    vector<pii> ansE;
    set<Node> S;

    for (int i = 1; i <= n; i++)
    {
        if (i == minIdx)
        {
            continue;
        }
        S.insert(Node(d[i], i, 1, minIdx));
        S.insert(Node(c[i], i, 0));
    }

    mark[minIdx] = 1;
    for (int i = 1; i < n; i++)
    {
        Node minNode = *S.begin();
        ans += minNode.d;
        if (minNode.type == 0)
        {
            ansV.push_back(minNode.idx);
            S.erase(S.begin());
            S.erase(Node(d[minNode.idx], minNode.idx, 1));
        }
        else
        {
            ansE.push_back(mp(minNode.idx, minNode.preIdx));
            S.erase(S.begin());
            S.erase(Node(c[minNode.idx], minNode.idx, 0));
        }
        mark[minNode.idx] = 1;
        int curIdx = minNode.idx;

        for (int i = 1; i <= n; i++)
        {
            if (mark[i])
            {
                continue;
            }
            if (dist[curIdx][i] < d[i])
            {
                S.erase(Node(d[i], i, 1));
                d[i] = dist[curIdx][i];
                S.insert(Node(d[i], i, 1, curIdx));
            }
        }
    }

    printf("%lld\n", ans);
    printf("%d\n", (int)ansV.size());
    for (auto v : ansV)
    {
        printf("%d ", v);
    }
    printf("\n");
    printf("%d\n", (int)ansE.size());
    for (auto e : ansE)
    {
        printf("%d %d\n", e.first, e.second);
    }
	
	
	return 0;
}

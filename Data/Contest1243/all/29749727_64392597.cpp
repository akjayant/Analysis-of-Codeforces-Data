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
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            pos.push_back(i);
        }
    }

    if (pos.size() > 2)
    {
        cout << "NO" << endl;
    }
    else if (pos.size() == 1)
    {
        if (s[pos[0]] == t[pos[0]])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (pos.size() < 1)
    {
        cout << "YES" << endl;
    }
    else if (s[pos[0]] == s[pos[1]] && t[pos[0]] == t[pos[1]])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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

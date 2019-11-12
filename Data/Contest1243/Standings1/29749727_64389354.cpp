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

int c[130];
void solve()
{
    memset(c, 0, sizeof(c));
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        c[s[i]]++;
        c[t[i]]++;
    }

    vector<pii> ans;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (c[ch] & 1)
        {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (t[i] == s[i]) continue;
        
        int j;
        for (j = i + 1; j < n && s[j] != s[i]; j++);

        if (j != n)
        {
            swap(t[i], s[j]);
            ans.push_back(mp(j, i));
            continue;
        }

        for (j = i + 1; j < n && t[j] != s[i]; j++);
        assert(j != n);
        swap(s[j], t[j]);
        swap(s[j], t[i]);
        ans.push_back(mp(j, j));
        ans.push_back(mp(j, i));
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (auto e : ans)
    {
        cout << e.first + 1 << " " << e.second + 1 << endl;
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

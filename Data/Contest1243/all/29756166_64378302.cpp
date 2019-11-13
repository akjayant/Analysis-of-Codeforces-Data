#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for(int ii = 0; ii < k; ++ii)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector <int> a;
        for(int i = 0; i < n; ++i)
            if (s[i] != t[i]) a.pb(i);
        if (int(a.size()) > 2 || int(a.size()) == 1)
        {
            cout << "No\n";
            continue;
        }
        if (int(a.size()) == 2)
        {
            swap(s[a[0]], t[a[1]]);
            if (s[a[0]] == t[a[0]] && s[a[1]] == t[a[1]])
            {
                cout << "Yes\n";
                continue;
            }
            swap(s[a[0]], t[a[1]]);
            swap(s[a[1]], t[a[0]]);
            if (s[a[0]] == t[a[0]] && s[a[1]] == t[a[1]])
            {
                cout << "Yes\n";
                continue;
            }
            cout << "No\n";
            continue;
        }
        if (int(a.size()) == 0)
        {
            set <char> st;
            for(int i = 0; i < n; ++i)
                st.insert(s[i]);
            bool f = false;
            for(int i = 0; i < n && !f; ++i)
            {
                if (st.count(t[i]) == 1)
                    f = true;
            }
            if (f)
            {
                cout << "Yes\n";
                continue;
            }
            else
            {
                cout << "No\n";
                continue;
            }
        }
    }
    return 0;
}

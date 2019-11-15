#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DISABLE_PERFCRIT_LOCKS
#define cdbg cerr << "Debug in " << __func__ << ", " << __LINE__ << ": "
#define q <<  '\n'
#define sp << ' '
#define pb emplace_back
#define mp make_pair
#define ft first
#define sd second
#define ld long double
#define ll long long
#define ull unsigned long long
#define pq priority_queue
//#define lll __int128
#define pii pair<ll , ll>
#define vi vector<ll>
using namespace std;

const int NN = 4e5;
const int INF = 1e9+1;
const ll MOD = 1e9+7;

ll n, m, t, arr[10001];
string str, kek;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pii> v;
        map<int, int> m;
        int a = 0;
        bool f = 0;
        cin >> str >> kek;
        for (int i = 0 ; i <n ;i++)
        {
            m[str[i]]++;
            m[kek[i]]++;
        }
        for (auto it : m)
        {
            if (it.sd % 2 == 1)
            {
                cout << "No" q;
                f = 1;
                break;
            }
        }
        if (f) continue;
        for (int i = 0 ; i < n; i++)
        {
            if (str[i] == kek[i]) continue;
            int pos = kek.find(str[i], i+1);
            if (pos == string::npos)
            {
                pos = str.find(str[i], i+1);
                v.pb(pos, i);
                swap(str[pos], kek[i]);
            }
            else
            {
                v.pb(pos, pos);
                v.pb(pos, i);
                swap(kek[pos], str[pos]);
                swap(str[pos], kek[i]);
            }
        }
        if (str != kek)
        {
            cout << "No" q;
            continue;
        }
        if (v.size() <= 2*n)
        {
            cout << "Yes" q;
            cout << v.size() q;
            for (auto it : v)
            {
                cout << it.ft+1 sp << it.sd+1 q;
            }
        }
        else cout << "No" q;
    }





















}

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
        vi v, v1;
        int a = 0;
        cin >> str >> kek;
        if (str == kek)
        {
            cout << "Yes" q;
            continue;
        }
        for (int i = 0 ; i < n; i++)
        {
            if (str[i] == kek[i]) a++;
            else
            {
                v.pb(str[i]);
                v1.pb(kek[i]);
            }
        }
        if (n-a == 0 || n-a == 2)
        {
           // cdbg << v[0] sp << v[1] sp << v1[0] sp << v1[1] q;
            if ((v[0] == v[1] && v1[0] == v1[1])) cout << "Yes" q;
            else cout << "No" q;
        }
        else cout << "No" q;
    }





















}

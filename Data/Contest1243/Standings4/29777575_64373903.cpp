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
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

        }
        for (int i = n; i >= 0; i--)
        {
            int ans = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] >= i) ans++;
            }
            if (ans >= i)
            {
                cout << i q;
                break;
            }
        }
    }





















}

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE
const int MOD = 1e9 + 7;
string s;

const int N = 100005;

int p[N];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    bool check = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'm' || s[i] == 'w') check = false;
    }
    if(!check)
    {
        cout << 0;
        return 0;
    }
    p[1] = 1;
    p[2] = 2;
    for(int i = 3; i < N; i++)
    {
        p[i] = (p[i - 1] + p[i - 2]) % MOD;
    }
    int d = 0;
    s.pb('a');
    int res = 1;
    if(s[0] == 'n') d = 1;
    if(s[0] == 'u') d = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) d += 1;
        else
        {
            if(s[i - 1] == 'u' || s[i - 1] == 'n')
            {
                res = res * p[d];
                res %= MOD;
            }
            d = 0;
            if(s[i] == 'u' || s[i] == 'n') d = 1;
        }
    }
    cout << res;

}

/**
    Code by: Best_Nakroth 12TH.


*/

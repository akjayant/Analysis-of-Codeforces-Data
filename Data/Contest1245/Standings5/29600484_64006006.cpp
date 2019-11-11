#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

//#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = (1 << 30) - 1;
const long long oo = (1ll << 62) - 1;
const long double PI = 3.1415926535898;
///BEGIN CODE

int t, n;
string s;
int a, b, c;

void solve()
{
    string res;
    res.clear();
    cin >> n;
    cin >> a >> b >> c;
    cin >> s;
    int d = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'R')
        {
            if(b)
            {
                b -= 1;
                d += 1;
                res.pb('P');
            }
            else
            {
                res.pb('X');
            }
        }
        if(s[i] == 'P')
        {
            if(c)
            {
                c -= 1;
                d += 1;
                res.pb('S');
            }
            else res.pb('X');
        }
        if(s[i] == 'S')
        {
            if(a)
            {
                a -= 1;
                d += 1;
                res.pb('R');
            }
            else res.pb('X');
        }
    }
    if(d >= (n + 1) / 2)
    {
        cout << "YES" << '\n';
        for(int i = 0; i < res.size(); i++)
        {
            if(res[i] == 'X')
            {
                if(a)
                {
                    cout << 'R';
                    a -= 1;
                    continue;
                }
                if(b)
                {
                    cout << 'P';
                    b -= 1;
                    continue;
                }
                if(c)
                {
                    cout << 'S';
                    c -= 1;
                    continue;
                }
            }
            else cout << res[i];
        }
    }
    else cout << "NO";
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();

}

/**
    Code by: Best_Nakroth 12TH.


*/

#include <bits/stdc++.h>

#define taskname ""
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> cd;
typedef vector <cd> vcd;
typedef vector <int> vi;

template<class T> using v2d = vector <vector <T> >;
template<class T> bool uin(T &a, T b)
{
    return a > b ? (a = b, true) : false;
}
template<class T> bool uax(T &a, T b)
{
    return a < b ? (a = b, true) : false;
}

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int maxN = 1e2 + 1;

int n, a, b, c;

char s[maxN];
bool flag[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int cntR = 0, cntS = 0, cntP = 0;
        cin >> n >> a >> b >> c >> (s + 1);
        for1(i, n)
        {
            if (s[i] == 'R')
            {
                ++cntR;
            }
            else if (s[i] == 'S')
            {
                ++cntS;
            }
            else
            {
                ++cntP;
            }
        }
        if (min(a, cntS) + min(b, cntR) + min(c, cntP) < ceil(n * 0.5))
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            memset(flag, 0, sizeof(flag));
            int cs = min(a, cntS);
            for1(i, n)
            {
                if (cs && s[i] == 'S')
                {
                    s[i] = 'R';
                    flag[i] = 1;
                    --cs;
                }
            }
            cs = min(b, cntR);
            for1(i, n)
            {
                if (cs && s[i] == 'R' && !flag[i])
                {
                    s[i] = 'P';
                    flag[i] = 1;
                    --cs;
                }
            }
            cs = min(c, cntP);
            for1(i, n)
            {
                if (cs && s[i] == 'P' && !flag[i])
                {
                    s[i] = 'S';
                    flag[i] = 1;
                    --cs;
                }
            }
            cs = a - min(a, cntS);
            for1(i, n)
            {
                if (cs && !flag[i])
                {
                    s[i] = 'R';
                    flag[i] = 1;
                    --cs;
                }
            }
            cs = b - min(b, cntR);
            for1(i, n)
            {
                if (cs && !flag[i])
                {
                    s[i] = 'P';
                    flag[i] = 1;
                    --cs;
                }
            }
            for1(i, n)
            {
                if (!flag[i])
                {
                    s[i] = 'S';
                }
            }
            for1(i, n)
            {
                cout << s[i];
            }
            cout << '\n';
        }
    }
    return 0;
}

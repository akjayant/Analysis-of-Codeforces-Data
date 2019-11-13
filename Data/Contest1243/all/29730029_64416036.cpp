#include <bits/stdc++.h>
#define getbit(x, i) (x >> (i - 1) & 1)
#define onbit(x, i) (x | (1 << (i - 1)))
#define offbit(x, i) (x ^ (1 << (i - 1)))
#define cntone(x) (__builtin_popcount(x))
#define sum(x, y, u, v) (f[u][v] - f[x - 1][v] - f[u][y - 1] + f[x - 1][y - 1])

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int oo = 1e9;
const int maxn = 1e6 + 10;

ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

template < typename T > inline void read(T &x)
{
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
}

template < typename T > void Write(T x)
{
    if(x > 9)
        Write(x / 10);
    putchar(x % 10 + 48);
}

int T, n, k;
string s, t;
vector < pii > res;

typedef vector < int > bignum;
const int base = 1e8;
const int digit = 8;

inline bignum str2big(string s)
{
    while(s.size() % digit) s = '0' + s;
    bignum res;
    for(int i = s.size() - 1; i >= 0; i -= digit)
    {
        ll t = 0;
        for(int j = i - digit + 1; j <= i; j++)
            t = t * 10 + s[j] - 48;
        res.push_back(t);
    }
    return res;
}

inline bool operator > (bignum x, bignum y)
{
    if(x.size() != y.size()) return (x.size() > y.size());
    for(int i = x.size() - 1; i >= 0; i--)
        if(x[i] != y[i])
            return (x[i] > y[i]);
    return false;
}

inline bool operator < (bignum x, bignum y)
{
    return (y > x);
}

inline bignum operator + (bignum x, bignum y)
{
    for(int i = 0, cur = 0; i < max(x.size(), y.size()) | cur; i++)
    {
        if(i == x.size()) x.push_back(0);
        x[i] = x[i] + (i < y.size() ? y[i] : 0) + cur;
        cur = (x[i] >= base);
        if(cur) x[i] -= base;
    }
    if(x.size() > 1 && !x.back()) x.pop_back();
    return x;
}

inline bignum operator - (bignum x, bignum y)
{
    for(int i = 0, cur = 0; i < x.size() || cur; i++)
    {
        x[i] = x[i] - (i < y.size() ? y[i] : 0) - cur;
        cur = (x[i] < 0);
        if(cur) x[i] += base;
    }
    while(x.size() > 1 && !x.back()) x.pop_back();
    return x;
}

inline bignum operator * (bignum P, ll k)
{
    for(int i = 0, cur = 0; i < P.size() || cur; i++)
    {
        if(i == P.size()) P.push_back(0);
        ll t = (ll)(P[i] * k + cur);
        cur = (ll)(t / base);
        P[i] = (ll)(t % base);
    }
    while(P.size() > 1 && !P.back()) P.pop_back();
    return P;
}

inline bignum operator * (bignum P, bignum Q)
{
    bignum res, tmp;
    for(int i = 0; i < P.size() + Q.size(); i++)
        res.push_back(0);
    for(int i = 0; i < P.size(); i++)
    {
        tmp = Q * P[i];
        tmp.insert(tmp.begin(), i, 0);
        res = res + tmp;
    }
    while(res.size() > 1 && !res.back()) res.pop_back();
    return res;
}
inline void display(bignum P)
{
    if(P.empty()) cout << 0;
    else cout << P.back();
    for(int i = P.size() - 2; i >= 0; i--)
        cout << setw(digit) << setfill('0') << P[i];
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("1.inp", "r"))
    {
       freopen("1.inp", "r", stdin);
       freopen("1.out", "w", stdout);
    }
    cin >> T;
    while(T--)
    {
        cin >> n >> s >> t;
        res.clear();
        for(int i = 0; i < n; i++)
            if(s[i] != t[i])
        {
            for(int j = i + 1; j < n; j++)
                if(t[i] == t[j])
                {
                    res.push_back(make_pair(i, j));
                    swap(s[i], t[j]);
                    break;
                }
                else if(s[j] == t[i])
                {
                    res.push_back(make_pair(i, i));
                    swap(s[i], t[i]);
                    res.push_back(make_pair(j, i));
                    swap(s[j], t[i]);
                    break;
                }
                else if(s[i] == t[j])
                {
                    res.push_back(make_pair(i, i));
                    swap(s[i], t[i]);
                    res.push_back(make_pair(i, j));
                    swap(s[i], t[j]);
                    break;
                }
        }
        if(s == t)
        {
            cout << "Yes\n" << res.size() << '\n';
            for(auto p : res) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
        }
        else cout << "No\n";
    }
    return 0;

}

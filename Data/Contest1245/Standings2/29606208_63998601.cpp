#pragma GCC optimize("Ofast,fast-math,unroll-loops")
  
#include <bits/stdc++.h>
  
#define int ll
//#define double long double
//#define endl '\n'
#define all(C) (C).begin(), (C).end()
#define rall(C) (C).rbegin(), (C).rend()
#define mp make_pair 
#define pb emplace_back
#define dbg(x) cerr << #x << " : " << x << endl
#define PI 3.14159265358979
  
using namespace std;
        
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair <int, int>;
        
/* 
const ll MAX_MEM = 7e8;
char MEM[MAX_MEM];
ll MEM_POS = 0;
void* operator new(size_t x)
{
    auto ret = MEM + MEM_POS;
    MEM_POS += x;
    assert(MEM_POS < MAX_MEM);
    return ret;
}
void operator delete(void*)
{}
*/
        
template <class T>
istream& operator>> (istream &in, vector <T> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}
        
template <class T> 
ostream& operator<< (ostream &out, vector <T> a)
{
    for (auto &i : a)
        out << i << ' ';
    return out;
}
        
template <class T, class U>
istream& operator>> (istream &in, pair <T, U> &p)
{
    in >> p.first >> p.second;
    return in;
}
        
template <class T, class U>
ostream& operator<< (ostream &out, pair <T, U> p)
{
    out << p.first << " " << p.second << " ";
    return out;
}
        
inline void Start()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
}
 
signed main()
{
    Start();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int kam, bum, noz;
        cin >> kam >> bum >> noz;
        string s;
        cin >> s;
        int x = 0;
        string t(n, '.');
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'P')
            {
                if (noz > 0)
                    --noz, ++x, t[i] = 'S';
            }
            else if (s[i] == 'S')
            {
                if (kam > 0)
                    --kam, ++x, t[i] = 'R';
            }
            else
            {
                if (bum > 0)
                    --bum, ++x, t[i] = 'P';
            }
        }
        if (x * 2 >= n)
        {
            cout << "YES\n";
            for (auto &i : t)
            {
                if (i == '.')
                {
                    if (bum > 0)
                        i = 'P', --bum;
                    else if (kam > 0)
                        i = 'R', --kam;
                    else
                        i = 'S', --noz;
                }
            }
            cout << t << endl;
        }
        else
            cout << "NO\n";
    }
    return 0;
}

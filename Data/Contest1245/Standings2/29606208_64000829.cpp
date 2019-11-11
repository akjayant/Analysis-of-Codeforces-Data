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

const int P = 1e9 + 7;
int add(int a, int b)
{
    return (a + b) % P;
}
int mul(int a, int b)
{
    return (a * b) % P;
}
 
signed main()
{
    Start();
    string s;
    cin >> s;
    int n = s.size();
    if (count(all(s), 'm') || count(all(s), 'w'))
        return cout << 0, 0;
    vector <int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (i >= 2)
        {
            if (s[i - 1] == s[i - 2])
            {
                if (s[i - 1] == 'u' || s[i - 1] == 'n')
                {
                    dp[i] = add(dp[i], dp[i - 2]);
                }
            }
        }
    }
    cout << dp[n];
    return 0;
}

#include <bits/stdc++.h>

#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sz size()
#define m_p make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef vector <pii> vpi;
typedef vector <pll> vpl;

mt19937_64 rnd(time(NULL));

const ll N = 1e6 + 10;
const ll oo = 1e9 + 10;
//const ll oo = 228;
const ll B = 500;
const ll mod = 1e9 + 7;

ll n, Q, a[100000], k1, i;

int main()
{
    //freopen("C.in", "r", stdin);
    //freopen("C.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> Q;
    while(Q){
        Q--;
        string s, s1;
        cin >> n;
        cin >> s >> s1;
        ll f = 0, col = 0;
        ll o;
        for(i = 0; i < n; ++i){
            if(s[i] != s1[i] && f){
                f = 2;
                break;
            }
            if(s[i] != s1[i] && col){
                if(s[o] == s[i] && s1[o] == s1[i]){
                        f = 1;
                }
                else{
                f = 2;
                break;
                }

            }
            if(s[i] != s1[i] && !col)col++, o = i;
        }
        if(f == 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
/*
3 3
1 2

3 3

5 26
4 4
2 4
6 8
5 6
2 7
9876543210

*/

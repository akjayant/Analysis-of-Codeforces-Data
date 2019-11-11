#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
#define fasty ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define task ""
#define For(a, b, c) for(int a = b; a <= c; ++a)
#define Ford(a, b, c) for(int a = b; a >= c; --a)
#define Fv(a, b) for(auto &a : b)
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x.size())
#define all(a) a.begin(), a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define vt vector<int>
#define vpi vector<pair<int, int>>
#define two(x) (1ll << x)
#define bit(x, i) (x >> i & 1ll)
#define onbit(x, i) (x | (1ll << i))
#define offbit(x, i) (x & ~(1ll << i))
int dd[1005];

main() {
    int test;
    cin >> test;
    while(test--) {
        reset(dd, 0);
        int n, a, b, c, x, y, z; string s;
        cin >> n >> a >> b >> c >> s;
        s = ' ' + s;
        x=0;
        For(i, 1, n) {
            if(s[i] == 'P' && c > 0) c--, x++, dd[i] = 3;
            if(s[i] == 'S' && a > 0) a--, x++, dd[i] = 1;
            if(s[i] == 'R' && b > 0) b--, x++, dd[i] = 2;
        }
        if(x < (n + 1) / 2) cout << "NO\n";
        else {
            int a1=a,b1=b,c1=c;
            cout << "YES\n";
            For(i,1,n) if(dd[i]==0)
            {
                if(a1>0) dd[i]=1,a1--;
                else if(b1>0) dd[i]=2,b1--;
                else dd[i]=3,c1--;
            }
            For(i,1,n)
            {
                if(dd[i]==1) cout << "R";
                if(dd[i]==2) cout << "P";
                if(dd[i]==3) cout << "S";
            }
            cout << "\n";
        }
    }
}

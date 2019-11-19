#include <bits/stdc++.h>

#define task "B"
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define Rep(i, r, l) for (int i = (r); i >= (l); --i)
#define pb push_back
#define F first
#define S second
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; } // sort(arr, arr + N, by(a));

using ll = long long;
using ld = long double;
using ull = unsigned long long;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vl;

// Limit

// Struct

// Variables
int T,n;
string s;
// Function

int main()
{
	//freopen(task".in","r",stdin);
	//freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> T;
	while (T--)
    {
        cin >> n >> s;
        int lef,rig;
        bool ok=0;
        rep(i,0,n-1) if (s[i]=='1')
        {
            lef=i+1;
            ok=1;
            break;
        }
        Rep(i,n-1,0) if (s[i]=='1')
        {
            rig=i+1;
            ok=1;
            break;
        }
        if (!ok) cout << n << '\n';
        else
        {
            cout << 2*max(n-lef+1,rig) << '\n';
        }
    }
}

#include <bits/stdc++.h>

#define task "A"
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
int T,a,b,c,d,k;
// Function

int main()
{
	//freopen(task".in","r",stdin);
	//freopen(task".out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	cin >> T;
	while (T--)
    {
        cin >> a >> b >> c >> d >> k;
        int res=(a+c-1)/c + (b+d-1)/d;
        if (res>k) cout << "-1\n";
        else cout << (a+c-1)/c << ' ' << (b+d-1)/d << '\n';
    }
}

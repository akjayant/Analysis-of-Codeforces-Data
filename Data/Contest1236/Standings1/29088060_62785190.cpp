#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double rl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair

#if 1
#define dbg(x) cerr << #x << ": " << (x) << endl;
#else
#define dbg(x)
#endif // 1

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    for(int u=0; u<t; u++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int result=min(c/2, b);
        b-=result;
        result+=min(a, b/2);
        
        cout << result*3 << '\n';
    }

    return 0;
}

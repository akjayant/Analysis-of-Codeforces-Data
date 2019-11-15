#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = b; i >= a; i--)
#define f first
#define s second
#define reset(x,a) memset (x,a,sizeof(x))
#define task ""
using namespace std;
const int MOD = 1e9 + 7;
const int N = 300005;
int t,a,b;
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--){
        cin >> a >> b;
        if (__gcd(a,b) != 1) cout << "Infinite" << endl;
        else cout << "Finite" << endl;
    }
    return 0;
}

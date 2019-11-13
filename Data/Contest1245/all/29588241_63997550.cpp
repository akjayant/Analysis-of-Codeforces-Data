#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define all(x) x.begin(), x.end()
#define len(x) ((int)x.size())

using namespace std;

//#define cout out
//#define cin in

ifstream in("inp.txt");
ofstream out("out.txt");

const ll M = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
    }

    return 0;
}
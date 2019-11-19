#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < (_n); ++i)
#define FJ(_n) for(int j = 0; j < (_n); ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int t;
    cin >> t;
    FJ(t)
    {
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        int k4 = 0;
        int n;
        cin >> n;
        FI(n)
        {
            int x;
            cin >> x;
            k1 += x & 1;
            k2 += !(x & 1);
        }
        int m;
        cin >> m;
        FI(m)
        {
            int x;
            cin >> x;
            k3 += x & 1;
            k4 += !(x & 1);
        }
        cout << (1ll * k1 * k3 + 1ll * k2 * k4) << endl;
    }

    return 0;
}

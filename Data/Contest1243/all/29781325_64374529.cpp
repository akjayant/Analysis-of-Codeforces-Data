#include <bits/stdc++.h>
#define FI(_n) for(int i = 0; i < _n; ++i)
#define FJ(_n) for(int j = 0; j < _n; ++j)
#define mp make_pair
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    ifstream cin("input.txt");
//    ofstream cout("output.txt");

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        FI(n)
            cin >> a[i];

        sort(a.begin(), a.end(), greater<int>());
        for (int i = n; i >= 1; --i)
        {
            if (a[i - 1] >= i)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

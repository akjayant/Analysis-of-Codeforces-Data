#include <bits/stdc++.h>

using namespace std;
#define intMax 1e18
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i >= b; i--)
#define be(a) (a.begin(), a.end())
#define rbe(p) (p.rbegin(), p.rend())
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int k = 0;
        vector<char> B, C;
        rep(i, 0, n)
        {
            if (a[i] != b[i])
            {
                B.pb(a[i]);
                C.pb(b[i]);
                    k++;
            }
        }
        if (k == 2)
        {
            swap(B[0], C[0]);
            sort be(C);
            sort be(B);
            if (C == B)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
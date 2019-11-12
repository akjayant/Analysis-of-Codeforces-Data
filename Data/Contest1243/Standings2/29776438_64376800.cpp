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
        vector<int> A(n);
        rep(i, 0, n)
        {
            cin >> A[i];
        }
        sort rbe(A);
        int ans = 0;
        int mini = intMax;
        int ans1 = 0;
        rep(i, 0, n)
        {
            mini = min(mini, A[i]);
            if (mini >= i + 1)
            {
                ans = max(ans, (i + 1) * (i+1));
            }
        }
        cout << sqrt(ans) << endl;
    }
}
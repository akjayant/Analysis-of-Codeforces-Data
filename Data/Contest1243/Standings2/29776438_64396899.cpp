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
        vector<pair<int, int>> ans;
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        map<char, int> A;
        rep(i, 0, n)
        {
            A[a[i]]++;
            A[b[i]]++;
        }
        bool kk = false;
        for (char i = 'a'; i <= 'z'; i++)
        {
            if (A[i] % 2 == 1)
            {
                cout << "No" << endl;
                kk = true;
                break;
            }
        }
        if (kk)
        {
            continue;
        }
        rep(i, 0, n)
        {
            if (a[i] != b[i])
            {
                rep(j, i + 1, n)
                {
                    if (a[i] == a[j])
                    {
                        swap(b[i], a[j]);
                        ans.pb({j + 1, i + 1});
                        break;
                    }
                    else if (a[i] == b[j])
                    {
                        swap(a[j], b[j]);
                        ans.pb({j + 1, j + 1});
                        swap(b[i], a[j]);
                        ans.pb({j + 1, i + 1});
                        break;
                    }
                }
            }
        }
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        rep(i, 0, ans.size())
        {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(v[i] >= n - i)
            {
                ans = max(ans, n - i);
            }
        }
        cout << ans << "\n";
    }
}

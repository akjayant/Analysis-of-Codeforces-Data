#include <bits/stdc++.h>

using namespace std;

int k, n, x, ans;
vector <int> ara;

int main()
{
  	iostream::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for (int p = 0 ; p < k ; p++)
    {
        cin >> n;
        ara.clear();
        for (int i = 0 ; i < n ; i++)
        {
            cin >> x;
            ara.push_back(x);
        }
        sort(ara.begin(), ara.end(), greater<int>());
        for (int i = 0 ; i < n ; i++)
        {
            if (ara[i] < i + 1)
                break;
            ans = i + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}

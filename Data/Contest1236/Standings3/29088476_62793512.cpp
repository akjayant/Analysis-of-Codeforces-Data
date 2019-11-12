#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (ll)1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> v[n];
    for (ll i = 0; i < n; i++)
    {
        vector<ll> temp;
        v[i] = temp;
    }
    ll count = 0;
    bool rev = 0;
    for (ll i = 1; i <= n * n; i++)
    {
        v[count].push_back(i);
        if (rev == 0)
        {
            if (count == n - 1)
            {
                rev = 1;
            }
            else
            {
                count++;
            }
        }
        else
        {
            if (count == 0)
            {
                rev = 0;
            }
            else
            {
                count--;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (auto j : v[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    int now = 0;
    for(int i = 0; i < n/2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[j].push_back(j+1+now);
        }
        now += n;
        for(int j = 0; j < n; j++)
        {
            ans[n-1-j].push_back(j+1+now);
        }
        now += n;
    }
    if(n % 2 == 1)
    {
        for(int j = 0; j < n; j++)
        {
            ans[j].push_back(j+1+now);
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

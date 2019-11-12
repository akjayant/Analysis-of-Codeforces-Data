#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;

typedef long long ll;

int n;

int a[302][302];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int val = n*n;
    for(int i = 1; i <= n; ++i)
    {
        if(i % 2 == 0)
        {
            for(int j = n; j >= 1; --j)
                a[j][i] = val, --val;
        }
        else
        {
            for(int j = 1; j <= n; ++j)
                a[j][i] = val, --val;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    return 0;
}

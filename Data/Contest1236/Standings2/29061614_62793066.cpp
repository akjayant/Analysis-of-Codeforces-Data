#include <bits/stdc++.h>
#define INF 1e18
#define M 1000000007
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[305][305];
    int k = 1;
    for(int j = 0; j < n; j++)
    {
        if(j & 1)
        {
            for(int i = n - 1; i >= 0; i--)
            {
                a[i][j] = k;
                k++;
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                a[i][j] = k;
                k++;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
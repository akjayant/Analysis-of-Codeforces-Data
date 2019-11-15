#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, k=1;
    cin >> n;
    int A[n][n];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int y = 0; y < n; y++)
            {
                A[i][y] = k;
                k++;
            }
        }
        else
        {
            for (int y = n-1; y >= 0; y--)
            {
                A[i][y] = k;
                k++;
            }
        }
    }
    for (int y = 0; y < n; y++)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[i][y] << " ";
        }
        cout << "\n";
    }
    return 0;
}

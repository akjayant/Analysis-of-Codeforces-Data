#include <bits/stdc++.h>
#define endl "\n"
#define INF (int)1e9
#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
    int n;
    cin >> n;
    int curr = 1;
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        int curr = i + 1;
        for (int j = 0; j < n; j++)
        {
            cout << curr << " ";
            if (j % 2 == 0)
            {
                curr += 2 * (n - i) - 1;
            }
            else
            {
                curr += 2 * (i + 1) - 1;
            }
        }
        cout << endl;
    }
}
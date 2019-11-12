#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int maxm = 1;

        for (int i = 0; i < n; ++i)
        {
             int a = arr[i];
             int b = n - i;

             maxm = max(maxm, min(a, b));
        }

        cout << maxm << "\n";
    }


    return 0;
}
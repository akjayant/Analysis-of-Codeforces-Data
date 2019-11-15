#include<bits/stdc++.h>

using namespace std;

#define Q int t, q; scanf("%d", &t); for(q=1; q<=t; q++)
#define lli long long int

int zero[1000000];

int main()
{
    Q
    {
        int n, mx = -1;
        cin >> n;
        int arr[n+1];
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);
        for(int i=0; i<n; i++){
            int x = min(arr[i], (n-i));
            mx = max(mx, x);

        }
        cout << mx << "\n";
    }

    return 0;
}

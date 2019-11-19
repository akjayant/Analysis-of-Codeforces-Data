#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[100000], sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];
    sort(arr, arr + n);

    int sh = 0;
    for (int i = 0; i < n / 2; i++)
        sh += arr[i];
    cout << sh * sh + (sum - sh) * (sum - sh) << '\n';

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***
//     *****  *****  *****
//    *      *   *  *
//   *      *****  *
//  *      *  *   *
//  ***** *   *   *****

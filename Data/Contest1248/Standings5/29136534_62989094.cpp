#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n; cin >> n;
    ll arr[n];
    for (int i=0 ; i<n ; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    ll i=0, a=0, b=0;
    for (i=0 ; i<n/2 ; i++)
        a+=arr[i];
    for (; i<n ; i++)
        b+=arr[i];
    cout << a*a+b*b;
    return 0;
}

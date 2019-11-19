#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
    	cin >> a[i];
    }
    sort(a, a+n);
    ll l=0, h=0;
    for (int i = 0; i < n/2; ++i)
    {
    	l+=a[i];
    }
    for (int i = n/2; i < n; ++i)
    {
    		h+=a[i];
    }
    cout << l*l+h*h<<"\n";
    return 0;
}
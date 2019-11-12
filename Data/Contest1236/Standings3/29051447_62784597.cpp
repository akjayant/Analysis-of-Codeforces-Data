#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
    	ll a, b, c;
    	cin >> a >> b >> c;
    	cout << 3*min(b, c/2)+3*min(a, (b-min(b, c/2))/2)<<"\n";

    }
    return 0;
}
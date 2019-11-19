/// don't hack me

/// follow me: https://www.instagram.com/rose_culbece/

#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define followmeoninsta ios_base::sync_with_stdio(0), cin.tie(0);
#define please if(1)

using namespace std;
int main()
{
    please followmeoninsta
    int t;
    cin >> t;
    for(; t; --t)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int nra = (a / c) + (a%c > 0);
        int nrb = (b / d) + (b%d > 0);
        if(nra + nrb <= k)
            cout << nra << " " << nrb << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}

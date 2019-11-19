#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        ll p = (a/c)+(a%c!=0);
        ll q = (b/d)+(b%d!=0);
        if(p+q>k)cout << -1 << "\n";
        else cout << p << " " << q << "\n";
    }
    return 0;
}

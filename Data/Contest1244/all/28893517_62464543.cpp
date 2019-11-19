#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,a,b,c,d,tmp,ans=0,k,pen,pc;
        cin >> a >> b >> c >> d >> k;
        pen = a/c + (a%c!=0);
        pc = b/d + (b%d!=0);
        if (pen+pc > k) cout << "-1\n";
        else cout << pen << " " << pc << "\n";
    }



    return 0;
}

#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define mod 1000000007
#define pii pair <long long,long long>

using namespace std;
int t,a,b;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(__gcd(a,b)!=1)
            cout<<"Infinite"<<endl;
        else cout<<"Finite"<<endl;
    }
}

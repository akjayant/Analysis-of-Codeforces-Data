#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(__gcd(a,b) > 1)
            cout<<"Infinite";
        else
            cout<<"Finite";
        cout<<"\n";
    }
}

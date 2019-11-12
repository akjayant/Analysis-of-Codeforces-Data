#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        ll x = min(b,c/2);
        ll count = 3*x;
        b = b-x;
        x = min(a,b/2);
        count += 3*x;
        cout<<count<<"\n";
    }   
    return 0;
}
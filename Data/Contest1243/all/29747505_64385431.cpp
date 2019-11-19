#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;

ll f(ll n){
    vector<ll>a; 
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            if(n/i == i)
                a.push_back(i);
            else{
                a.push_back(n/i);
                a.push_back(i);
            }
        }
    }

    a.push_back(n);

    ll ans = a[0];
    for(auto i: a)
        ans = __gcd(ans, i);

    return ans;
}
int main()
{
    ll n;
    cin>>n;


    cout<<f(n)<<"\n";
    return 0;
}

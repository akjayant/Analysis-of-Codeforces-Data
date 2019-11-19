#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pi acos(-1)
#define N 1000005
#define mod 1000000007
using namespace std;
int main()
{
    IOS
    ll test;
    cin>>test;
    while(test--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll fc=0, bc=0;
        for(ll i=0; i<n; i++){
            if(s[i]=='1')break;
            fc++;
        }
        for(ll i=n-1; i>=0; i--){
            if(s[i]=='1')break;
            bc++;
        }
        ll ans=min(fc, bc);
        cout<<max((2*n)-(2*ans), n)<<endl;

    }


    return 0;
}

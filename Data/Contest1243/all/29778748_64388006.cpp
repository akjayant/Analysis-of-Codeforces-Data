//Bismillahir rahmanir rahim
#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define debug(x) cout << #x << ": " << x << "\n";
using namespace std;

int main()
{
    ll n;
    scanf("%lld",&n);
    ll gc = 0;
    for(ll i = 2;i <= sqrt(n);i++){
        if(n % i == 0){
            gc = __gcd(gc,i);
            gc = __gcd(gc,n/i);
        }
    }
    if(gc == 0) printf("%lld\n",n);
    else printf("%lld\n",gc);
    return 0;
}

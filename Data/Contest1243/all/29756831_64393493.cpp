#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    ll i = 2;
    ll ans = -1;
    ll cnt = 0;
    vector<ll> pf;
    while(i * i <= n){
        if(n % i == 0){
            cnt++;
            pf.push_back(i);
            while(n > 1 && n % i == 0){
                n /= i;
            }
        }
        i++;
    }
    if(n > 1){
        pf.push_back(n);
        cnt++;
    }
    if(cnt == 0){
        ans = n;
    }else if(cnt == 1){
        ans = pf[0];
    }else{
        ans = 1;
    }
    cout << ans;
    return 0;
}

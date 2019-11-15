// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>
#include<set>

#define ll long long
// #define umap unordered_map

using namespace std;

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    else return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        ll ans = 0;
        for(ll i=n-1; i>=0; i--){
            ll w = n-i;
            ll h = a[i];
            ans = max(ans, min(w,h));
        }

        cout << ans << endl;
    }    

    return 0;
}

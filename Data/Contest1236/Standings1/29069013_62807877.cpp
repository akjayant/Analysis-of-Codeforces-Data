#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pi;
 
ll mod = 1e9 + 7;

bool comp(pi a, pi b){
    return a.F < b.F || (a.F == b.F && a.S < b.S);
}

ll func(ll x, ll y){
    if (y == 0)
        return 1;
    ll temp = func(x, y/2);
    temp = (temp*temp)%mod;
    if (y%2){
        return (temp*x)%mod;
    }
    else
        return temp%mod;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    ll n, m, k;
    cin >> n >> m >> k;
    set < pair<ll, ll> > s;
    for(ll i = 0; i < k; i++){
        ll a, b;
        cin >> a >> b;
        s.insert({a,b});
    }
    ll l = 1;
    ll r = m;
    ll u = 1;
    ll d = n;
    while(l <= r && d >= u){
        // cout << "1 " << u << " " << d << " " << l << " " << r << endl; 
        while (s.find({u, r}) != s.end()){
            for(int i = u; i <= d; i++){
                auto itr = s.find({i, r});
                if (itr == s.end()){
                    cout << "No";
                    return 0;
                }
                else
                    s.erase(itr);
            }
            r--;
        }
        u++;
        // cout << "2 " << u << " " << d << " " << l << " " << r << endl; 

        while (s.find({d, r}) != s.end()){
            for(int i = l; i <= r; i++){
                auto itr = s.find({d, i});
                if (itr == s.end()){
                    cout << "No";
                    return 0;
                }
                else
                    s.erase(itr);
            }
            d--;
        }
        r--;
        // cout << "3 " << u << " " << d << " " << l << " " << r << endl; 

        while (s.find({d, l}) != s.end()){
            for(int i = u; i <= d; i++){
                auto itr = s.find({i, l});
                if (itr == s.end()){
                    cout << "No";
                    return 0;
                }
                else
                    s.erase(itr);
            }
            l++;
        }
        d--;
        // cout << "4 " << u << " " << d << " " << l << " " << r << endl; 

        while (s.find({u, l}) != s.end()){
            for(int i = l; i <= r; i++){
                auto itr = s.find({u, i});
                if (itr == s.end()){
                    cout << "No";
                    return 0;
                }
                else
                    s.erase(itr);
            }
            u++;
        }
        l++;
    }
    // cout << "jivsj";
    if (s.size() != 0)
        cout << "No";
    else
        cout << "Yes";

}
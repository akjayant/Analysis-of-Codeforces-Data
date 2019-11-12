// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
#include<unordered_map>
    
#define ll long long
    
using namespace std;

ll M = 1e9 + 7;

ll powr(ll a, ll b){
    if(b==0) return 1;
    if(a==0) return 0;
    ll ret = 1;
    while(b){
        if(b&1){
            ret *= a;
            ret %= M;
        }
        a = (a*a)%M;
        b /= 2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;
    cin >> k;

    while(k--){
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<ll> sc;

        // for(ll i=0; i<n; i++){
        //     if(s[i]!=t[i]){
        //         sc.push_back(i);
        //     }
        // }

        vector<vector<ll> > ans;
        ll ctr = 0;

        for(ll i=0; i<n; i++){
            if(s[i]==t[i]) continue;

            for(ll j=i+1; j<n; j++){
                if(s[j]==s[i]){
                    char temp = s[j];
                    s[j] = t[i];
                    t[i] = temp;
                    ans.push_back( {j+1, i+1} );
                    break; 
                }

                if(s[i]==t[j]){
                    char temp = s[j];
                    s[j] = t[j];
                    t[j] = temp;
                    ans.push_back( {j+1, j+1} );

                    temp = t[i];
                    t[i] = s[j];
                    s[j] = temp;
                    ans.push_back( {j+1, i+1} );

                    break;
                }
            }
        }

        if(s==t){
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for(ll i=0; i<ans.size(); i++){
                cout << ans[i][0] << " " << ans[i][1] << endl;
            }
        }
        else cout << "No" << endl;
    }

    return 0;
}
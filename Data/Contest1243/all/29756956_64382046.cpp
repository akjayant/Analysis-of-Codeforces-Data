#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin>>k;
    vector<string> ans(k);
    for (ll j=0; j<k; j++){
        map<pair<char,char>,ll> m;
        ll n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        ll cnt = 0;
        ll gen = 0;
        for (ll i=0; i<n; i++){
            if (s[i]!=t[i]){
                m[{s[i], t[i]}]++;
                gen++;
            }
            if ( m[{s[i], t[i]}]==2)
                cnt++;
        }
        if (gen==2 && cnt==1){
            ans[j]="Yes";
        }
        else {
            ans[j]="No";
        }
    }
    for (ll i=0; i<k; i++)
        cout<<ans[i]<<"\n";
    return 0;
}

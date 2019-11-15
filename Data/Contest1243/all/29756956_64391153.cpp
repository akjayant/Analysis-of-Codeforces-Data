#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll k;
    cin>>k;
    vector<string> ans(k);
    vector<vector<pair<ll,ll>>> steps(k);
    for (ll j=0; j<k; j++){
        unordered_map<char, ll> cnt;
        ll n;
        cin>>n;
        string s, t;
        cin>>s>>t;
        for (ll i=0; i<n; i++){
            cnt[s[i]]++;
            cnt[t[i]]++;
        }
        for (ll i=0; i<n; i++){
            if (cnt[s[i]]%2){
                ans[j]="No";
            }
            if (cnt[t[i]]%2){
                ans[j]="No";
            }
        }
        if (ans[j]!="No")
            ans[j]="Yes";
        for (ll i=0; i<n; i++){
            if (s[i]==t[i])
                continue;
            ll p=i+1;
            while (p<n && t[p]!=s[i]){
                p++;
            }
            if (t[p]==s[i]){
                steps[j].push_back({i+1, i+1});
                steps[j].push_back({i+1, p+1});
                swap(t[i], t[p]);
            }
            else {
                p = i+1;
                while (p<n && s[p]!=s[i]){
                    p++;
                }
                steps[j].push_back({p+1, i+1});
                swap(s[p], t[i]);
            }
        }
    }
    for (ll i=0; i<k; i++){
        cout<<ans[i]<<"\n";
        if (ans[i]=="Yes"){
            cout<<steps[i].size()<<"\n";
            for (ll j=0; j<steps[i].size(); j++){
                cout<<steps[i][j].first<<" "<<steps[i][j].second<<"\n";
            }
        }
    }
    return 0;
}

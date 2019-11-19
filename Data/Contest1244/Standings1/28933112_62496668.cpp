#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

vector<int> tonari[100010];

void solve(){
    int n; ll k; cin>>n>>k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll mini=a[0],maxi=a[n-1],cntmini=1,cntmaxi=0;

    for (int i = 1; i < n; ++i) {
        if(a[i]!=mini) break;
        cntmini++;
    }

    for (int i = n-1; i >= 0; --i) {
        if(a[i]!=maxi) break;
        cntmaxi++;
    }

    while(maxi-mini>0){
        if(k<cntmini&&k<cntmaxi) break;
        if(cntmini<cntmaxi){ //増やす
            ll saidai=a[cntmini]-mini;
            if(saidai*cntmini>k){
                mini+=k/cntmini;
                break;
            }
            k-=saidai*cntmini;
            mini+=saidai;
            for (int i = cntmini; i < n; ++i) {
                if(a[i]>mini) break;
                cntmini++;
            }
        }else{
            ll saidai=maxi-a[n-1-cntmaxi];
            if(saidai*cntmaxi>k){
                maxi-=k/cntmaxi;
                break;
            }
            k-=saidai*cntmaxi;
            maxi-=saidai;
            for (int i = n-1-cntmaxi; i>=0; --i) {
                if(a[i]<maxi) break;
                cntmaxi++;
            }
        }
    }

    cout<<max(maxi-mini,0ll)<<endl;

    return;
}


int main() {
    solve();
    return 0;
}

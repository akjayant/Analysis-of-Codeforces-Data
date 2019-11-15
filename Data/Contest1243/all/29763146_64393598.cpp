#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MOD=1e9+7;
const ll INF=1e18;
ll t,n;
string str1,str2;
vector<pair<ll,ll> >ans;
void solve(){
    ans.clear();
    for(ll i=0;i<n;i++){
        if(str1[i]!=str2[i]){
            ll flag=0;
            for(ll j=i+1;j<n;j++){
                if(str1[j]==str1[i]){
                    swap(str1[j],str2[i]);
                    ans.push_back(make_pair(j,i));
                    flag=1;
                    break;
                }
            }
            if(!flag) {
                for (ll j = i + 1; j < n; j++) {
                    if (str2[j] == str1[i]) {
                        swap(str2[j], str1[j]);
                        swap(str1[j], str2[i]);
                        ans.push_back(make_pair(j, j));
                        ans.push_back(make_pair(j, i));
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag){
                printf("NO\n");
                return;
            }
        }

    }
    printf("YES\n");
    printf("%d\n",ans.size());
    for(ll i=0;i<ans.size();i++){
        printf("%lld %lld\n",ans[i].first+1,ans[i].second+1);
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        cin>>str1;
        cin>>str2;
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t-->0){
        ll n,r,p,s;
        string str;
        cin>>n>>r>>p>>s>>str;

        string ans = "";
        for(ll i=0;i<n;i++)ans+="*";
        ll wins = 0;
        for(ll i=0;i<n;i++){
            if(str[i]=='R'){
                if(p)ans[i]='P' , p-- , wins++;
            }
            else if(str[i]=='P'){
                if(s)ans[i]='S' , s-- , wins++;
            }
            else{
                if(r)ans[i]='R' , r-- , wins++;
            }
        }
       // debug(ans);
        if(wins<(n+1)/2){
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for(ll i=0;i<n;i++){
            if(ans[i]!='*'){
                cout<<ans[i];
            }
            else{
                if(p){
                    cout<<"P";
                    p--;
                }
                else if(r){
                    cout<<"R";
                    r--;
                }
                else if(s){
                    cout<<"S";
                    s--;
                }
            }
        }
        cout<<"\n";
    }
}


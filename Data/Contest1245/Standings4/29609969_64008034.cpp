#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, r, p, s;
        cin>>n;
        cin>>r>>p>>s;
        string seq;
        cin>>seq;
        int wins = 0;
        string ans = seq;
        for(int i=0; i<n; i++){
            ans[i] = '#';
            if(seq[i]=='R'){
                if(p){
                    wins++;
                    p--;
                    ans[i] = 'P';
                }
            } else if(seq[i]=='P'){
                if(s){
                    wins++;
                    s--;
                    ans[i] = 'S';
                }
            } else {
                if(r){
                    wins++;
                    r--;
                    ans[i] = 'R';
                }
            }
        }
        if((n%2==1&&wins>n/2)||(n%2==0&&wins>=n/2)){
            cout<<"YES"<<endl;
            for(int i=0; i<n; i++){
                if(ans[i]=='#'){
                    if(r){
                        ans[i] = 'R';
                        r--;
                    } else if(p){
                        ans[i] = 'P';
                        p--;
                    } else {
                        ans[i] = 'S';
                        s--;
                    }
                }
            }
            cout<<ans<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
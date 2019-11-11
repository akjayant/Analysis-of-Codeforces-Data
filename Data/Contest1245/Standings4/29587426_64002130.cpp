#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const ll MOD = 1e9+7;

int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        int a,b,c,n;
        string str;
        cin >> n >> a>>b>>c>>str;
        vector<char> ans(n, 'X');
        int cnt=0;
        for(int i=0;i<n;i++){
            if(str[i] == 'R' && b){
                b--;
                ans[i] = 'P';
                cnt++;
            }
            if(str[i] == 'P' && c){
                c--;
                cnt++;
                ans[i] = 'S';
            }
            if(str[i] == 'S' && a){
                a--;
                cnt++;
                ans[i] = 'R';
            }
        }
        int req = (n+1)/2;
        if(cnt < req){
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        for(int i=0;i<n;i++){
            if(ans[i] == 'X'){
                if(a) {
                    ans[i] = 'R';
                    a--;
                    continue;
                }
                if(b) {
                    ans[i] = 'P';
                    b--;
                    continue;
                }
                if(c) {
                    ans[i] = 'S';
                    c--;
                    continue;
                }
            }
        }
        for(int i=0;i<n;i++) cout << ans[i];
        cout <<"\n";
    }
    return 0;
}
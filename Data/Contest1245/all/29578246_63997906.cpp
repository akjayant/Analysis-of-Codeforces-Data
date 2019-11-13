#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf=(1ll<<61);
const int MX=3e5+9;
int t,n,r,p,s;
string s1;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>r>>p>>s;
        cin>>s1;
        string ans="";
        for(int i=0;i<n;i++)ans.push_back('0');
        int j=-1;
        int res=0;
        for(auto pp:s1){
            j++;
            if(pp == 'P' && s){
                s--;res++;
                ans[j] = 'S';
            }
            if(pp == 'R' && p){
                p--;res++;
                ans[j] = 'P';
            }
            if(pp == 'S' && r){
                r--;res++;
                ans[j] = 'R';
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i] == '0'){
                if(r){
                    ans[i]='R';
                    r--;
                }
                else if(p){
                    ans[i] = 'P';
                    p--;
                }
                else if(s){
                    ans[i]  = 'S';
                    s--;
                }
            }
        }
        if(res*2 >= n){
            puts("YES");
            cout<<ans<<endl;
        }
        else puts("NO");
    }
}

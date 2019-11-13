#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,a,b,c;
string s;
char ans[555];
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while (t--){
        cin>>n>>a>>b>>c>>s;//rps
        memset(ans,0, sizeof(ans));
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R'){
                if(b)b--,cnt++,ans[i]='P';
            }else if(s[i]=='P'){
                if(c)c--,cnt++,ans[i]='S';
            }else{//=s
                if(a)a--,cnt++,ans[i]='R';
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]!='P'&&ans[i]!='S'&&ans[i]!='R'){
                if(a){
                    a--,ans[i]='R';
                }else if(b){
                    b--,ans[i]='P';
                }else {
                    c--,ans[i]='S';
                }
            }
        }
        if(cnt>=(n+1)/2){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<ans[i];
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
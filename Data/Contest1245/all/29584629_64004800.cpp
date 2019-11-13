#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")


int main(){
    int t;
    cin>>t;
    for(;t;t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int x=a,y=b,z=c;
        string s;
        cin>>s;
        int r=0,p=0,sr=0;
        for(char c:s){
            if(c=='R'){
                
                r++;
            }
            if(c=='P')p++;
            if(c=='S')sr++;
        }
        int w=(min(r,y)+min(p,z)+min(sr,x));
        if(w>=( (n+1)/2)){
            cout<<"YES\n";
            string ans;
            for(char c:s)ans.push_back('a');
            for(int i=0;i<s.size();i++){
                if(s[i]=='R'&&b){
                    b--;
                    ans[i]='P';
                }
                if(s[i]=='P'&&c){
                    c--;
                    ans[i]='S';
                }
                if(s[i]=='S'&&a){
                    a--;
                    ans[i]='R';
                }
            }
            for(int i=0;i<s.size();i++){
                if(ans[i]=='a'&&b){
                    b--;
                    ans[i]='P';
                }
                if(ans[i]=='a'&&c){
                    c--;
                    ans[i]='S';
                }
                if(ans[i]=='a'&&a){
                    a--;
                    ans[i]='R';
                }
            }
            cout<<ans<<endl;
        }else{
            cout<<"NO\n";
        }
    }
}
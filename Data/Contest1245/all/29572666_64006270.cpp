#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c,t,ans[101];
string s;
int main(){
    cin>>T;
    while(T--){
        t=0;
        memset(ans,0,sizeof ans);
        cin>>n>>a>>b>>c>>s;
        for(int i=0;i<n;++i){
            if(s[i]=='S'&&a)--a,ans[i]='R',++t;
            if(s[i]=='R'&&b)--b,ans[i]='P',++t;
            if(s[i]=='P'&&c)--c,ans[i]='S',++t;
        }
        for(int i=0;i<n;++i){
            if(!ans[i]){
                if(a)--a,ans[i]='R';
                else if(b)--b,ans[i]='P';
                else ans[i]='S';
            }
        }
        if(2*t<n)puts("NO");
        else{
            puts("YES");
            for(int i=0;i<n;++i)putchar(ans[i]);
            cout<<endl;
        }
    }
}
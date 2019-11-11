#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

const LL p=1e9+7;
string s;
LL f[100001];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    f[1]=1;f[2]=2;
    rep(i,3,s.length()+1) f[i]=(f[i-1]+f[i-2])%p;
    LL ans=1,l=-1;char ch;
    s+='#';
    rep(i,0,s.length()){
        if(l>=0&&s[i]!=ch){
            int len=i-l;l=-1;
            ans=ans*f[len]%p;
        }
        if(s[i]=='n'||s[i]=='u'){
            if(l<0) l=i,ch=s[i];
        }
        if(s[i]=='m'||s[i]=='w'){
            cout<<0<<endl;return 0;
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Ford(a,b,c) for(int a=b;a>=c;--a)
#define Fv(a,b) for(auto &a:b)
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x.size())
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) (x>>i&1ll)
#define on(x,i) (x|(1ll<<i))
#define off(x,i) (x&~(1ll<<i))
#define task "1243c"
string s,t;
int n;
main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;
    cin>>test;
    while(test--){
        cin>>n;
        cin>>s>>t; int oo=0;
        vector<int>pos;
        For(i,0,n-1){
            if(s[i]!=t[i]) oo++,pos.pb(i);
        }
        if(oo>=3||oo==1) {cout<<"NO\n";continue;}
        else{
                int ok=1,ok1=1;
            swap(s[pos[0]], t[pos[1]]);
            For(i,0,n-1) if(s[i]!=t[i]) {
                ok=0;
                break;
            }
            swap(s[pos[0]], t[pos[1]]);
            swap(s[pos[1]], t[pos[0]]);
            For(i,0,n-1) if(s[i]!=t[i]){
                ok1=0;
                break;
            }
            if(ok==1||ok1==1)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

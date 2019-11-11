#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int >
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define LL long long
using namespace std;
const int INF=0x3f3f3f3f,N=2e6+5,MOD=1e9+7;

int f(int x){
    return (x+1)/2;
}

int ans[N];
int Solve(){
    int n,a,b,c;
    string str;
    cin>>n>>a>>b>>c>>str;
    vi ans(n,0);
    int suc=0,win=f(n);
    for(int i=0;i<n;i++){
        if(str[i]=='R'){
            if(b)b--,suc++,ans[i]='P';
        }
        else if(str[i]=='P'){
            if(c)c--,suc++,ans[i]='S';
        }
        else {
            if(a)a--,suc++,ans[i]='R';
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i]==0){
            if(a)a--,ans[i]='R';
            else if(b)b--,ans[i]='P';
            else c--,ans[i]='S';
        }
    }
    if(suc>=win){
        cout<<"YES"<<endl;
        // for(auto p:ans)cout<<(char)p;cout<<endl;
        for(int i=0;i<n;i++)cout<<(char)ans[i];cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
void Pre(){
}
int main() {
#ifndef ONLINE_JUDGE
 freopen("in.txt","r",stdin);
//  freopen("o1.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    Pre();
    int cas;cin>>cas;
    while(cas--)Solve();
    return 0;
}


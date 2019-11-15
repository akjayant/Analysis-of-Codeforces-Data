#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
char ans[N];
int main(){
    int t; cin>>t;
    while(t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        string bob;
        cin>>bob;
        memset(ans,0,sizeof(ans));
        int R=0,S=0,P=0,res=0;
        int tmp = (n+1)/2;
        for(int i=0;i<n;i++){
            if(bob[i]=='R') if(b) ans[i] = 'P',res++,b--;
            if(bob[i]=='P') if(c)ans[i] = 'S',res++,c--;
            if(bob[i]=='S') if(a) ans[i] = 'R',res++,a--;
        }
        if(res>=tmp){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++)
                if(ans[i]=='P' || ans[i]=='R' || ans[i]=='S') cout<<ans[i];
                else {
                    if(a) cout<<'R',a--;
                    else if(b) cout<<'P',b--;
                    else if(c) cout<<'S',c--;
                }
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}

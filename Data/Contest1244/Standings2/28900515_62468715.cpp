#include<bits/stdc++.h>
#define rep(i,b,e) for(LL i=(b);i<(e);++i)
#define dep(i,b,e) for(LL i=(b);i>=(e);--i)
#define LL long long

using namespace std;

int t,a,b,c,d,k,ans;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        int x=a/c+(a%c>0);
        int y=b/d+(b%d>0);
        if(x+y>k) cout<<-1<<endl;
        else{
            cout<<x<<' '<<y<<endl;
        }
    }
    //system("pause");
    return 0;
}

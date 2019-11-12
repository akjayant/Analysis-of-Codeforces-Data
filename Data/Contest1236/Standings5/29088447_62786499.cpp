#include<bits/stdc++.h>
#define int long long
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin>>T;
    while(T--){
        int a,b,c; cin>>a>>b>>c;
        int ans=0;
        for(int i=0;i<=100;i++) for(int j=0;j<=100;j++){
            if(i<=a and 2*i+j<=b and 2*j<=c){
                chmax(ans,(i+j)*3);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    std::ios::sync_with_stdio(false);
    int t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int ans=min(b,c/2);
        b-=ans;
        ans*=3;
        ans+=min(a,b/2)*3;
        cout<<ans<<"\n";
    }
    return 0;
}

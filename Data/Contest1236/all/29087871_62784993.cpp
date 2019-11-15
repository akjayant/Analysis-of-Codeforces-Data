#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=0 ; i<t ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=0;
        for(int j=0 ; j<=a && j*2<=b ; j++){
            ans=max(ans,j*3+min(b-2*j,c/2)*3);

        }
        cout<<ans<<"\n";
    }
    return 0;
}

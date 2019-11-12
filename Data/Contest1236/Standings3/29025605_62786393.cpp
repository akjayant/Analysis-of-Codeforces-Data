#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,a,b,c;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        int ans=0;
        for(int i=0;i<=50;i++) {
            for(int j=0;j<=50;j++) {
                if(i>a||2*i+j>b||2*j>c) continue;
                else {
                    ans=max(ans,3*i+3*j);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

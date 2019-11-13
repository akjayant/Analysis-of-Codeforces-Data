#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a , b , c;
        cin>>a>>b>>c;
        int ans = 0;
        while(b && c >= 2){
            b--;
            c -= 2;
            ans += 3;
        }
        while(b >= 2 && a){
            b-=2;
            a--;
            ans += 3;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
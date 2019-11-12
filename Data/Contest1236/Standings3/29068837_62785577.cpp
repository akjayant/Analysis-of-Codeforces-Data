#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+50;
int main(){
    int T,a,b,c;
    cin>>T;
    while(T--){
        cin>>a>>b>>c;
        if(b>=c/2) cout<<(min((b-c/2)/2,a)+c/2)*3<<endl;
        else cout<<min(b,c/2)*3<<endl;
    }
    return 0;
}
